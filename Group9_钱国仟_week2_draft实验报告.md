
# Week2实验报告
## 一、实验任务
本次实验基于Linux、Python/C++开发环境及ROS1 Noetic框架，需完成6大核心实训任务，具体如下：
1. **Linux基础命令练习**：完成文件的创建/移动/删除、apt软件安装、进程的查看与终止操作，掌握Linux终端核心指令。
2. **Python与C++编程练习**：编写并运行Python HelloWorld程序、C++数字求和程序，完成g++编译和VSCode调试实操。
3. **ROS1 Noetic安装验证**：验证roscore启动状态、查询ROS节点列表、检查ROS环境变量配置有效性。
4. **CATKIN工作空间与功能包**：创建catkin_ws工作空间和beginner_tutorials功能包，编写并运行HelloWorld节点，熟悉ROS工程结构。
5. **Turtlesim小乌龟基础控制**：实现小乌龟的键盘控制、rostopic话题速度控制，编写程序完成小乌龟自动画圆。
6. **多乌龟Launch与rqt工具使用**：编写Launch文件启动多只小乌龟并分配独立命名空间，通过rostopic分别控制乌龟，用rqt_graph查看通信关系、rqt_plot绘制速度曲线。

## 二、实现过程
### 1. Linux基础命令练习
- **文件管理**
  1. 执行`mkdir test_dir`创建测试目录，`touch test.txt`创建测试文件；
  2. 执行`mv test.txt test_dir/`移动文件，`rm -rf test_dir`删除目录及文件。
- **软件安装**
  1. 执行`sudo apt update`更新软件源；
  2. 执行`sudo apt install tree`安装tree工具，完成apt安装流程验证。
- **进程管理**
  1. 执行`ps -aux`查看系统所有进程，定位目标进程PID；
  2. 执行`kill [PID]`终止指定进程，完成进程管控。

### 2. Python与C++编程练习
- **Python HelloWorld**
  1. 新建`hello.py`文件，写入代码`print("Hello World")`；
  2. 终端执行`python3 hello.py`，输出对应内容。
- **C++数字求和**
  1. 创建`sum.cpp`文件，编写包含输入输出流的求和代码；
  2. 执行`g++ sum.cpp -o sum`编译生成可执行文件，运行`./sum`实现数字输入与求和。
- **VSCode调试**
  1. 打开VSCode加载代码文件，配置`launch.json`调试配置；
  2. 添加断点并启动调试，完成代码基础调试。

### 3. ROS1 Noetic安装验证
1. 终端输入`roscore`，确认ROS Master启动成功，无端口占用异常；
2. 新开终端执行`rosnode list`，查看当前ROS系统节点，验证节点通信基础环境；
3. 执行`echo $ROS_PACKAGE_PATH`，确认输出路径包含ROS核心包和自定义工作空间路径。

### 4. CATKIN工作空间与功能包
- **创建工作空间**
  1. 执行`mkdir -p catkin_ws/src`创建目录结构；
  2. 进入catkin_ws目录，执行`catkin_make`完成编译；
  3. 执行`source devel/setup.bash`配置工作空间环境变量。
- **创建功能包**
  进入src目录，执行`catkin_create_pkg beginner_tutorials roscpp rospy std_msgs`，创建含ROS基础依赖的功能包。
- **运行HelloWorld节点**
  1. 在功能包src目录编写C++/Python版本HelloWorld节点代码；
  2. 编译后执行`rosrun beginner_tutorials [节点名称]`，终端输出HelloWorld信息。

### 5. Turtlesim小乌龟基础控制
- **键盘控制**
  1. 终端1执行`rosrun turtlesim turtlesim_node`启动仿真窗口；
  2. 终端2执行`rosrun turtlesim turtle_teleop_key`，通过方向键控制小乌龟移动。
- **rostopic控制**
  执行`rostopic pub /cmd_vel geometry_msgs/Twist "linear: {x: 1.0, y: 0.0, z: 0.0}; angular: {x: 0.0, y: 0.0, z: 0.5}" -r 10`，通过话题控制小乌龟做圆周运动。
- **程序控制画圆**
  1. 编写Python/C++代码，通过ROS Publisher持续发布固定线速度和角速度指令；
  2. 编译运行后实现小乌龟自动画圆。

### 6. 多乌龟Launch与rqt工具使用
- **编写Launch文件**
  创建`multi_turtle.launch`文件，配置2个turtlesim节点，分别分配`/turtleA`和`/turtleB`命名空间。
- **启动多乌龟节点**
  执行`roslaunch beginner_tutorials multi_turtle.launch`，打开多只小乌龟仿真窗口。
- **分别控制乌龟**
  针对不同命名空间，执行`rostopic pub /turtleA/cmd_vel [速度指令]`和`rostopic pub /turtleB/cmd_vel [速度指令]`，实现独立控制。
- **rqt工具查看**
  1. 执行`rqt_graph`查看节点与话题通信拓扑图；
  2. 执行`rqt_plot`绘制乌龟速度变化曲线，验证多节点通信状态。

## 三、遇到的问题和解决方法
1. **问题**：执行`catkin_make`提示“未找到ROS环境”，编译失败
   **解决方法**：先执行`source /opt/ros/noetic/setup.bash`配置系统级ROS环境变量，再重新执行`catkin_make`完成编译。
2. **问题**：rosrun启动自定义节点提示“找不到节点”
   **解决方法**：检查`CMakeLists.txt`的节点编译规则和`package.xml`依赖配置，编译后执行`source devel/setup.bash`更新环境，重新启动节点。
3. **问题**：rostopic控制多乌龟时指令无响应
   **解决方法**：通过`rostopic list`确认话题名称，修正指令中的命名空间拼写错误，重新发送指令后乌龟成功响应。

## 四、总结与心得
通过本次Week2实验，我系统掌握了机器人开发基础工具链和ROS1核心能力：
1. 熟练使用Linux终端核心指令，掌握了文件、软件和进程的基础管理逻辑；
2. 完成Python/C++开发环境搭建，具备了简单程序的开发与调试能力；
3. 理解ROS1基础架构，能独立创建工作空间和功能包，掌握节点编写与运行方法，初步认知ROS通信机制；
4. 实现Turtlesim多方式控制，掌握Launch文件批量启动节点技巧，理解命名空间的多节点管理作用，学会用rqt工具分析ROS通信状态。

同时认识到ROS开发中环境变量和文件路径的重要性，后续需加强ROS通信机制和Launch高级语法的学习，提升复杂场景工程实践能力。