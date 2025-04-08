#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <cmath>
#include <std_msgs/Float32.h>

// 重力加速度
const double g = 9.8;

int main(int argc, char** argv) {
    // 初始化 ROS 节点
    ros::init(argc, argv, "robot_position_node");
    ros::NodeHandle nh;

    // 创建 TF 监听器
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);

    // 创建发布器
    ros::Publisher velocity_pub = nh.advertise<std_msgs::Float32>("shooting_velocity", 10);

    ros::Rate rate(10.0); // 设置循环频率 10Hz

    // 设置篮筐参数
    double hoop_x = 5.6;    // 篮筐X坐标
    double hoop_y = 0;    // 篮筐Y坐标
    double hoop_height = 2.43; // 篮筐高度
    double robot_height = 1; //投篮高度
    double m = 0.625;          // 篮球质量 (kg)
    double k = 0.01;           // 空气阻力系数 (kg/m)
    while (ros::ok()) {
        try {
            // 获取 odom -> base_link 的变换
            geometry_msgs::TransformStamped transformStamped = tfBuffer.lookupTransform("map", "base_link", ros::Time(0));

            // 读取机器人坐标
            double robot_x = transformStamped.transform.translation.x;
            double robot_y = transformStamped.transform.translation.y;

            // 打印坐标
            ROS_INFO("robot_position: x = %.3f, y = %.3f", robot_x, robot_y);

            // 计算距离
            double shooting_angle = 60.0;  // 投篮角度 60°
            double shooting_angle_rad = shooting_angle * M_PI / 180.0; // 转为弧度

            double dx = hoop_x - robot_x;
            double dy = hoop_y - robot_y;
            double dz = hoop_height - robot_height; // Z轴的高度差
            double horizontal_distance = sqrt(dx * dx + dy * dy); // 水平总距离
             
            
            // 计算投篮的初速度
            double cos_theta = cos(shooting_angle_rad);
            double tan_theta = tan(shooting_angle_rad);
            double sin_theta = sin(shooting_angle_rad);

            // 计算公式中的分母部分
            double denominator = 2 * (cos_theta * cos_theta) * (robot_height - hoop_height + horizontal_distance * tan_theta);

            // 检查分母是否为0，防止除以零
            if (denominator <= 0) {
                ROS_WARN("no v");
                continue;  // 如果不可计算，跳过这次循环
            }

            // 使用公式计算初速度
            double v0 = sqrt((g * horizontal_distance * horizontal_distance) /
                             denominator);
            //考虑空气阻力
            double v0_final = v0 * (1 + k * horizontal_distance / m); // 简化的阻力修正  

            double tf = horizontal_distance/ (v0 * cos_theta);
            double t_max = v0 * sin_theta / g;

            if ( t_max >= tf){
                ROS_WARN("no_verb");
            }
            // 发布初速度
            std_msgs::Float32 velocity_msg;
            velocity_msg.data = v0_final;
            velocity_pub.publish(velocity_msg);

            // 打印初速度
            ROS_INFO("Initial v: %.2f m/s", v0_final);

        } catch (tf2::TransformException &ex) {
            ROS_WARN("%s", ex.what());
        }

        rate.sleep();
    }

    return 0;
}