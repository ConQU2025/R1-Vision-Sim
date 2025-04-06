#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "base_tf_broadcaster");
    ros::NodeHandle nh;

    tf2_ros::TransformBroadcaster br;
    geometry_msgs::TransformStamped transformStamped;

    ros::Rate rate(50.0); // 50Hz 发布频率

    while (ros::ok()) {
        transformStamped.header.stamp = ros::Time::now();
        transformStamped.header.frame_id = "base_footprint";
        transformStamped.child_frame_id = "base_link";

        // 设置 base_link 相对于 base_footprint 的位置 (z=0.05)
        transformStamped.transform.translation.x = 0.0;
        transformStamped.transform.translation.y = 0.0;
        transformStamped.transform.translation.z = 0.05;

        // 设置旋转 (无旋转，单位四元数)
        transformStamped.transform.rotation.x = 0.0;
        transformStamped.transform.rotation.y = 0.0;
        transformStamped.transform.rotation.z = 0.0;
        transformStamped.transform.rotation.w = 1.0;

        // 发送 TF 变换
        br.sendTransform(transformStamped);

        rate.sleep();
    }

    return 0;
}
