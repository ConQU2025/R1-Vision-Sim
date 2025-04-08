#include <ros/ros.h>
#include <serial/serial.h>
#include <conqu/ByteArray.h>
#include <std_msgs/String.h>
#include <sstream>

void sendCallback(const conqu::ByteArray::ConstPtr& msg, serial::Serial& ser) {
    try {
        size_t data_size = msg->data.size();
        ser.write((uint8_t*)msg->data.data(), data_size);

        std::ostringstream oss;
        for (size_t i = 0; i < data_size; i++) {
            oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned>(msg->data[i]) << " ";
        }
        std::string hex_str = oss.str();
        ROS_INFO("Sent: [%s]", hex_str.c_str());
    } catch (const serial::IOException& e) {
        ROS_ERROR("Failed to send data: %s", e.what());
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "serial_comm_cpp");
    ros::NodeHandle nh;
    ros::NodeHandle priv_nh("~");

    std::string port;
    int baudrate;
    priv_nh.param<std::string>("port", port, "/dev/ttyUSB0");
    priv_nh.param("baud", baudrate, 115200);

    serial::Serial ser;
    try {
        ser.setPort(port);
        ser.setBaudrate(baudrate);
        serial::Timeout timeout = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(timeout);
        ser.open();
        ROS_INFO_STREAM("Connected to " << port << " at " << baudrate << " baud");
    } catch (const serial::IOException& e) {
        ROS_ERROR_STREAM("Failed to open serial port: " << e.what());
        return -1;
    }

    ros::Publisher pub = nh.advertise<std_msgs::String>("serial_receive", 10);
    ros::Subscriber sub = nh.subscribe<conqu::ByteArray>("serial_send", 10, boost::bind(sendCallback, _1, boost::ref(ser)));

    ros::Rate loop_rate(100);
    while (ros::ok()) {
        if (ser.available()) {
            std_msgs::String msg;
            msg.data = ser.read(ser.available());
            pub.publish(msg);
            ROS_INFO_STREAM("Received: " << msg.data);
        }
        ros::spinOnce();
        loop_rate.sleep();
    }

    ser.close();
    return 0;
}