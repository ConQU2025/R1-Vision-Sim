#include <ros/ros.h>
#include <std_msgs/Float32.h>

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "float_publisher");
    ros::NodeHandle nh;
    
    // 创建发布者
    ros::Publisher float_pub = nh.advertise<std_msgs::Float32>("float_topic", 10);
    
    // 设置发布频率为1Hz
    ros::Rate loop_rate(10);
    
    // 设置固定的float值
    std_msgs::Float32 msg;
    msg.data = 3.14;  // 发送固定的3.14
    
    while (ros::ok())
    {
        // 发布消息
        ROS_INFO("Publishing: %.2f", msg.data);
        float_pub.publish(msg);
        
        // 处理回调函数
        ros::spinOnce();
        
        // 按照设定频率休眠
        loop_rate.sleep();
    }
    
    return 0;
}