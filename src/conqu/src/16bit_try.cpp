#include <ros/ros.h>
#include <std_msgs/UInt8MultiArray.h>

int main(int argc, char **argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "hex_publisher");
    ros::NodeHandle nh;

    // 创建发布者，发布到"hex_data"话题
    ros::Publisher pub = nh.advertise<std_msgs::UInt8MultiArray>("hex_data", 10);

    // 设置发布频率为1Hz
    ros::Rate rate(10);

    // 用户定义的12字节16进制数据数组
    uint8_t hex_data[12] = {
        0x98, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6,
        0x78, 0x90, 0x12, 0x67, 0x56, 0x34
    }; // 请在这里修改为您想要的12字节16进制数据

    while (ros::ok()) {
        // 创建消息
        std_msgs::UInt8MultiArray msg;
        msg.data.assign(hex_data, hex_data + 12);

        // 发布消息并打印日志
        std::stringstream ss;
        ss << "Publishing: [";
        for (size_t i = 0; i < msg.data.size(); ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)msg.data[i];
            if (i < msg.data.size() - 1) ss << ", ";
        }
        ss << "]";
        ROS_INFO("%s", ss.str().c_str());
        pub.publish(msg);

        // 处理回调并休眠
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}