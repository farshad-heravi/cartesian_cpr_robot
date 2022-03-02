#include <cpr_robot.h>

/* NOTE: It is required to include this class in the cpr_robot library
*        1. create a 'drylin_gantry.h' file in 'ws/src/cpr_robot/include/cpr_robot/'
*        2. in the file 'ws/src/cpr_robot/include/cpr_robot.h' add the line: '#include "cpr_robot/drylin_gantry.h"'
*        3. ONLY IF YOU WANT A RVIZ SIMULATION: create the urdf drylin_gantry file in 'ws/src/cpr_robot/robots/'
*        4. create the executable file of the robot class such as: 'ws/src/cpr_robot/src/dryling_gantry.cpp'
*        5. create a main file such as: 'ws/src/cpr_robot/src/main_dryling_gantry.cpp'
*        6. add the two .cpp files to the 'CMakeLists.txt' file such as:
*               add_executable(drylin_gantry 
                  src/main_drylin_gantry.cpp 
                  src/Bus.cpp 
                  src/MotorModule.cpp 
                  src/Robot.cpp 
                  src/Joint.cpp 
                  src/drylin_gantry.cpp 
                )
                target_link_libraries(drylin_gantry ${catkin_LIBRARIES})
                add_dependencies(drylin_gantry cpr_robot_generate_messages_cpp)
*/
namespace cpr_robot
{
    drylin_gantry::drylin_gantry() :
        Robot(2,1)
    {
        set_ModelName("drylin_gantry");
        
        // Joint 1: https://www.igus.it/product/20794?artNr=MOT-AN-S-060-035-060-M-C-AAAS
        set_JointName(0,"x");                           // Nema 24 stepper motor, holding torque 3.5 Nm @ X-axis ZLW-1040-S
        set_GearRatio(0,1.0);                           // transmission rate (r_Joint / r_Motor): 1
        set_TicksPerMotorRotation(0,2000);              // encoder steps: 500 impulse / turn = 2000 (500 * 4)
        set_MaxVelocity(0,50.0);                        // maximum angular velocity of the JOINT [degrees / s]: see graph
        set_MinPosition(0,-140.0);                      // lower position bound of the JOINT [degrees]: unknown = axis length / radius
        set_MaxPosition(0,140.0);                       // upper position bound of the JOINT [degrees]: unknown
        set_MotorOffset(0,0);                           // zero-position of the MOTOR in encoder ticks: user-defined
        
        // linear guide: 70 mm / 2*pi --> x_radius = 11.14 mm
        
        /*
        * NOTE: GearRatio is here defined as radius of the joint / radius of the motor
        *
        * pos: JOINT position in radians
        * ticks: corresponding MOTOR position in encoder ticks
        * motorRotations        =       pos * GearRatio / (2.0 * PI)            [--]
        * ticks                 =       motorRotations * TicksPerMotorRotation  [ticks]
        
        * Converts a motor position to a JOINT position.
        * ticks: MOTOR position in encoder ticks
        * position: corresponding JOINT position in radians
        * K = 360 / TicksPerMotorRotation [degrees / tick]
        * motorRotation_deg     =       ticks * K  = ticks * (360/TicksPerMotorRotation)  [degrees]
        * motorRotation_rad     =       motorRotations_deg * (2*PI/360)
        * jointRotation_rad     =       motorRotation_rad / GearRatio
        */
        
        // Joint 2: https://www.igus.it/product/1300?artNr=MOT-ST-56-L-C-A
        set_JointName(1,"y");                      // Nema 23, holding torque 2.0 Nm
        set_GearRatio(1,1.0);        
        set_TicksPerMotorRotation(1,2000);        
        set_MaxVelocity(1,50.0);
        set_MinPosition(1,0.0);
        set_MaxPosition(1,140.0); 
        set_MotorOffset(1,0);
        
        // linear guide: 70 mm / 2*pi --> y_radius = 11.14 mm
        
        define_Output(true,0,0,"Digital out 1");
        define_Output(true,0,1,"Digital out 2");
        define_Output(true,0,2,"Digital out 3");
        define_Output(true,0,3,"Digital out 4");
        define_Output(true,0,4,"Digital out 5");
        define_Output(true,0,5,"Digital out 6");
        define_Output(true,0,6,"Digital out 7");
        define_Input(true,0,0,"Digital in 1");
        define_Input(true,0,1,"Digital in 2");
        define_Input(true,0,2,"Digital in 3");
        define_Input(true,0,3,"Digital in 4");
        define_Input(true,0,4,"Digital in 5");
        define_Input(true,0,5,"Digital in 6");
        define_Input(true,0,6,"Digital in 7");
    }

    //! Destructs an instance of the drylin_gantry class  
    drylin_gantry::~drylin_gantry()
    {

    }

}