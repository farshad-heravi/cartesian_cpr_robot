// This node listens to trajectory points from ROS
// does the inversse kinematics and then 
// published the required joint commands.

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
#include <boost/foreach.hpp>

void subs_callback(const std_msgs::StringPtr& msgs ){
    ROS_INFO_STREAM("MSG: " << msg);
}

void cartesian_ik(){
    return;
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "cartesian_robot_ik");
    ros::NodeHandle nh;


    // TODO read robot and joint names from rosparam to create corresponding node handles.
    ros::NodeHandle robot_nh(nh, "cartesian_");
    std::vector<std::string> motor_names = {"joint1", "joint2", "joint3"};
    
    // define node handlse and publishers for each joint
    std::vector<ros::NodeHandle> joint_nhs;
    std::vector<ros::Publisher> joint_pubs;
    BOOST_FOREACH(const std::string &motor_name, motor_names)
    {
        ros::NodeHandle joint_nh(robot_nh, motor_name);
        joint_nhs.push_back( joint_nh );

        ros::Publisher pub = joint_nh.advertise<std_msgs::Float64>("position_controller/command",10);
        joint_pubs.push_back( pub );
    }

    // set subscriber to get target points
    // CONFIG
    ros::Subscriber sub = nh.subscribe("topicname", 10, subs_callback);


    return 1;
}