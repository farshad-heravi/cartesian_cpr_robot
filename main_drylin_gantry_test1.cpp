#include <cpr_robot.h>
#include <sstream>
#include <cmath>

int mode = 0;                   // 0: no synchronization, 1: synchronization
float x_radius = 11.14;
float y_radius = 11.14;
float xdot_ref = 0.0;
float ydot_ref = 0.0;
float qdot_x = 0.0;
float qdot_y = 0.0;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "drylin_gantry");
  cpr_robot::drylin_gantry robot;
  robot.Init();
  
  ros::Rate loop_rate(10);
  
  // Subscribe to the trajectory topic
  
  
  while (ros::ok())
  {
    // Inverse Kinematic
    qdot_x = xdot_ref / x_radius;
    qdot_y = ydot_ref / y_radius;
    
    // Mode A
    if (mode == 0)
    {
      robot.m_pJoints[0].m_DesiredVelocity = qdot_x;
      robot.m_pJoints[1].m_DesiredVelocity = qdot_y;
      
      robot.set_Override(1);
      robot.Write(); // --> for each joint: Joint.Write(override) --> m_pModule.set_Increment(desiredTicks) --> changes the attribute of the Module called "m_MotorIncrement" --> m_pModule.WriteLoop() calls set_DesiredPosition(m_MotorPosition+m_MotorIncrement) --> Command_SetJoint(m_MotorPosition, m_DOutputs) --> writes on the CAN bus
    }
    
    // Mode B
    else
    {
      // This requires the WriteLoop() method of MotorModule.cpp to be commented so to do nothing
      robot.m_pJoints[0].m_pModule.set_DesiredPosition(m_MotorPosition+m_MotorIncrement);
      robot.m_pJoints[0].m_pModule.Command_SetJoint(m_MotorPosition, m_DOutputs);
      
      robot.m_pJoints[1].m_pModule.set_DesiredPosition(m_MotorPosition+m_MotorIncrement);
      robot.m_pJoints[1].m_pModule.Command_SetJoint(m_MotorPosition, m_DOutputs);
    }
    
    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}
