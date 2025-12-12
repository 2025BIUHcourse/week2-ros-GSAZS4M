#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "turtle_circle_node");
    ros::NodeHandle nh;

    // 创建发布者，发布到/turtle1/cmd_vel话题
    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Rate rate(10);  // 10Hz

    // 初始化速度消息
    geometry_msgs::Twist vel_msg;
    vel_msg.linear.x = 1.0;
    vel_msg.angular.z = 0.5;

    ROS_INFO("小乌龟开始画圆");

    // 循环发布速度指令
    while (ros::ok())
    {
        vel_pub.publish(vel_msg);
        rate.sleep();
    }

    return 0;
}

