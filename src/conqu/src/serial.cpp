#include <ros/ros.h>
#include <serial/serial.h>
#include <conqu/ByteArray.h>
#include <std_msgs/String.h>
#include <sstream>

serial::Serial ser;

void sendCallback(const conqu::ByteArray::ConstPtr& msg) {
    // 直接发送 10 个字节的原始数据
    ser.write((uint8_t*)msg->data.data(), 10);

    // 打印发送的数据（十六进制）
    std::ostringstream oss;
    for (int i = 0; i < 10; i++) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)msg->data[i] << " ";
    }
    ROS_INFO("Sent: [%s]", oss.str().c_str());
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "serial_comm_cpp");
    ros::NodeHandle nh;
    ros::NodeHandle priv_nh("~");
    
    std::string port;
    int baudrate;
    priv_nh.param<std::string>("port", port, "/dev/ttyUSB0");
    priv_nh.param("baud", baudrate, 115200);
    
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
    ros::Subscriber sub = nh.subscribe("serial_send", 10, sendCallback);
    
    ros::Rate loop_rate(100); // 100Hz
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