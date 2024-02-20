#!/bin/bash

###### DESCRIPTION ######
### Usage: differential inspection system
### Precaution: Run realsense-cam-X.sh First
######

### ARGUMENTS ###
LAUNCH_RVIZ=1 # 1 to launch rviz, any other value will skip launching rviz
###

ROS_DISTRO=noetic
source /opt/ros/$ROS_DISTRO/setup.bash

cd /home/extraction-ws
source devel/setup.bash

# Launch differential
roslaunch rs-pcl2 diff.launch &

if [ "$LAUNCH_RVIZ" -eq 1 ]; then
    roslaunch rs-pcl2 rviz.launch
fi

wait