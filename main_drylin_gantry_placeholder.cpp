#include <cpr_robot.h>
#include <sstream>
#include <cmath>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "drylin_gantry");
  cpr_robot::drylin_gantry robot;
  robot.Init();
  
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    robot.Read();                       // --> for each joint: Joint.Read() --> Joint.OnRead() --> current velocity, current position, ...
    robot.PublishState();
    robot.Write();
    
    // useful methods
    robot.get_Override();               // override value used to control the speed of the joints
    robot.get_Input(0);
    robot.get_Output(0);
    robot.get_Input(1);
    robot.get_Output(1);
    robot.m_pJoints[0].Read();
    robot.m_pJoints[1].OnWrite();
    robot.m_pJoints[1].Write(override);
    robot.m_pJoints[0].ReadPosition(??);
    robot.m_pJoints[0].get_CurrentPosition();
    robot.m_pJoints[0].get_CurrentVelocity();
    
    robot.m_pJoints[0].m_pModule.set_Increment(desiredTicks);
    robot.m_pJoints[0].m_pModule.Command_SetJoint(ticks, doutput);
    robot.m_pJoints[0].m_pModule.get_UpdateInterval();
    robot.m_pJoints[0].m_pModule.Command_ResetError();
    robot.m_pJoints[0].m_pModule.Command_DisableMotor();
    
    // probably it is sufficient to just change the 'm_MotorIncrement' attribute of the MotorModule object, and the internal
    // WriteLoop() automatically sends the Command_setJoint() (see line 129 of MotorModule.cpp)
    
    
    /*
    * VELOCITY "CONTROL"
    * Nel loop, for each time instant t_k:
    *   1. set the desired velocity at time k: robot.m_pJoints[0] = xdot_ref, robot.m_pJoints[1] = ydot_ref, where xdot_ref 
    *      and ydot_ref are the JOINT velocities expressed in degrees per seconds
    *   2. set the override value (between 0 and 1) that scales the desired velocity: robot.set_Override(value);
    *   3. write the reference value in the firmware: robot.Write();
    * NOTE: robot.Write() --> for each jonint: joint.Write() --> OnWrite() --> setIncrement(a), where a is the computed number
    *       of encoder ticks based on the user specified desired velocity and on the fixed update time interval
    * HENCE, the given trajectory can be tracked by an open-loop velocity control as intended above. The only required step
    * involves scaling the reference trajectory in order to express it in degrees per seconds, basically multiplying each
    * value for the gear ratio * radius of the joint, like in the following (see "drylin_gantry.cpp"):
    * jointRotation_rad     =     motorRotation_rad / GearRatio
    * jointLinear_mm        =     jointRotation_rad * jointRadius_mm
    */
    
    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}
