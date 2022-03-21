// This node listens to trajectory points from ROS
// does the inversse kinematics and then 
// published the required joint commands.

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Header.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Point.h>
#include <boost/foreach.hpp>


std::vector<ros::Publisher> joint_pubs;

void publish_command(std::vector<double> &pos, std::vector<double> &vel, std::vector<double> &cur){
    // sensor_msgs::JointState cmd;
    // std_msgs::Header header = std_msgs::Header();
    // header.stamp = ros::Time::now();
    // cmd.header = header;
    // cmd.position = pos;
    // cmd.velocity = vel;
    // cmd.effort = cur;
    // joint_pubs[0].publish(cmd);

    // TODO temporary for only position controllers
    int i = 0;
    BOOST_FOREACH(double position, pos)
    {
        std_msgs::Float64 cmd;
        cmd.data = position;
        joint_pubs[i].publish(cmd);
        i++;
    }
}

void cartesian_ik(const double &x, const double &y, const double &theta){
    // calculate joint1, joint2, and joint3 positions
    std::vector<double> temp = {x,y,theta};
    std::vector<double> zero = {0,0,0};
    publish_command(temp,zero,zero);
}

void subs_callback(const geometry_msgs::PointConstPtr &msg ){ // TODO message type
    ROS_INFO_STREAM("Target Point: [" << msg->x << ", " << msg->y << ", " << msg->z << "]");
    // call inverse kinematics functions
    cartesian_ik(msg->x, msg->y, msg->z);
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "cartesian_robot_ik");
    ros::NodeHandle nh;


    // TODO read robot and joint names from rosparam to create corresponding node handles.
    ros::NodeHandle robot_nh(nh, "cartesian_");
    std::vector<std::string> motor_names = {"joint1", "joint2", "joint3"};
    
    // define node handlse and publishers for each joint
    std::vector<ros::NodeHandle> joint_nhs;
    BOOST_FOREACH(const std::string &motor_name, motor_names)
    {
        ros::NodeHandle joint_nh(robot_nh, motor_name);
        joint_nhs.push_back( joint_nh );

        ros::Publisher pub = joint_nh.advertise<std_msgs::Float64>("position_controller/command",10);
        joint_pubs.push_back( pub );
    }

    // set subscriber to get target points
    // CONFIG
    ros::Subscriber sub = nh.subscribe<geometry_msgs::Point>("topicname", 10, subs_callback);
    ros::Rate rate(50);
    while(ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
    }
    return 1;
}