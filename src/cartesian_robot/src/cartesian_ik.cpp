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
std::vector<double> joints_ratio;       // ratio: linear motion / rotation motion

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
    // convert x, y, z to motor rotation angles in rad.
    std::vector<double> temp;


    // TODO correct these
    temp.push_back( x / joints_ratio[0] );
    temp.push_back( y / joints_ratio[1] );
    temp.push_back( theta );
    // TODO apply offsetss
    
    std::vector<double> zero = {0,0,0};
    // publish commands
    publish_command(temp,zero,zero);
}

void subs_callback(const geometry_msgs::PointConstPtr &msg ){ // TODO message type
    ROS_DEBUG_STREAM("Target Point: [" << msg->x << ", " << msg->y << ", " << msg->z << "]");
    // call inverse kinematics functions
    cartesian_ik(msg->x, msg->y, msg->z);
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "cartesian_robot_ik");
    ros::NodeHandle nh;     // since it is running in a group. nh is not the root node handle. it is /name_space

    // get joint names from rosparam
    std::vector<std::string> motor_names;
    std::string joint_name;
    double joint_ratio;
    nh.param<std::string>("joint1", joint_name, "joint1");
    nh.param<double>("joint1/ratio", joint_ratio, 1);
    motor_names.push_back(joint_name);
    joints_ratio.push_back(joint_ratio);
    nh.param<std::string>("joint2", joint_name, "joint2");
    nh.param<double>("joint2/ratio", joint_ratio, 1);
    joints_ratio.push_back(joint_ratio);
    motor_names.push_back(joint_name);
    nh.param<std::string>("joint3", joint_name, "joint3");
    nh.param<double>("joint3/ratio", joint_ratio, 1);
    motor_names.push_back(joint_name);
    joints_ratio.push_back(joint_ratio);
    
    // define node handlse and publishers for each joint
    std::vector<ros::NodeHandle> joint_nhs;
    BOOST_FOREACH(const std::string &motor_name, motor_names)
    {
        ros::NodeHandle joint_nh(nh, motor_name);
        joint_nhs.push_back( joint_nh );

        ros::Publisher pub = joint_nh.advertise<std_msgs::Float64>("position_controller/command",10);
        joint_pubs.push_back( pub );
    }

    // set subscriber to get target points
    // CONFIG topicname
    std::string target_point_topic = "/cartesian_/TargetPoint";
    ros::Subscriber sub = nh.subscribe<geometry_msgs::Point>(target_point_topic, 10, subs_callback);
    ros::Rate rate(200);
    while(ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
    }
    return 1;
}