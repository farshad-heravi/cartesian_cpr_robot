#pragma once

namespace cpr_robot
{
	//! \class drylin_gantry drylin_gantry.h <cpr_robot.h>
	//! \brief Class representing a robolink 2DOF small version robot from igus. 
	//!
	//! All model specific parameters are handled by this class
    class drylin_gantry : public Robot
    {
        public:
            drylin_gantry();
            virtual ~drylin_gantry();
    };
}
