#include <ros/ros.h>
#include <conqu/ByteArray.h>
#include <vector>

int main(int argc, char** argv) {
    ros::init(argc, argv, "serial_sender");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<conqu::ByteArray>("serial_send", 10);
    ros::Rate loop_rate(100); // 1Hz

    std::vector<std::vector<int8_t>> messages = {
        {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A}, // 第一组
        {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A}, // 第二组
        {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A}  // 第三组
    };
    size_t index = 0;

    while (ros::ok()) {
        conqu::ByteArray msg;  
        // 填充 10 个字节数据
        for (int i = 0; i < 10; i++) {
            msg.data[i] = messages[index][i];
        }

        pub.publish(msg);
        // 打印发送的数据（十六进制）
        std::ostringstream oss;
        for (int i = 0; i < 10; i++) {
            oss << std::hex << std::setw(2) << std::setfill('0') << (int)msg.data[i] << " ";
        }
        ROS_INFO("Published: [%s]", oss.str().c_str());

        index = (index + 1) % messages.size();

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}