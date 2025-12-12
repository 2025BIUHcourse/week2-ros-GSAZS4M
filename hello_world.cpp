#include "ros/ros.h"  // ROS 核心头文件

int main(int argc, char **argv)
{
    // 初始化 ROS 节点，节点名：hello_world_node
    ros::init(argc, argv, "hello_world_node");
    // 创建节点句柄（管理 ROS 资源）
    ros::NodeHandle nh;
    
    // 输出日志（ROS_INFO 等价于 printf）
    ROS_INFO("Hello World! This is beginner_tutorials node.");
    
    // 保持节点运行（若无循环，节点会立即退出）
    ros::spin();
    return 0;
}
