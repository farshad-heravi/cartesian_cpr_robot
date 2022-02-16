# cpr_robot
ROS support; sources for hardware interface nodes and RViz pluing to run CPR robots with the ROS environment. Usable for igus robolink and CPR Mover robots.


# build

use the code below to build the packages
```
catkin_make
```
and source the package
```
source devel/setup.bash
```


# cartesian_description package
The package has three launch files which can be used for bringup, rviz, and gazebo
```
roslaunch cartesian_description cartesian_bringup.launch
```
or
```
roslaunch cartesian_description cartesian_rviz.launch
```
or
```
roslaunch cartesian_description cartesian_gazebo.launch
```