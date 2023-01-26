cd peak-linux-driver-8.15.2
sudo modprobe pcan
sudo modprobe can
sudo modprobe vcan
sudo modprobe slcan
#sudo modprobe can_dev
#sudo modprobe can_raw
sudo ip link set can0 type can bitrate 500000
sudo ip link set can0 up

#source smb_repo_ws/devel_isolated/setup.bash
#source smb_repo_ws/cl
#devel/setup.bash

roslaunch cartesian_description cartesian_bringup.launch simulation:=false
