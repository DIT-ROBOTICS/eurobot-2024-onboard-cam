#!/bin/bash

###### DESCRIPTION ######
### Usage: differential inspection system
### Precaution: Run realsense-cam-1.sh First
######

ROS_DISTRO=noetic
source /opt/ros/$ROS_DISTRO/setup.bash

cd /home/extraction-ws
source devel/setup.bash

# Launch differential
roslaunch rs-pcl2 diff.launch &

# Set LAUNCH_RVIZ to 1 to launch rviz, any other value will skip launching rviz
LAUNCH_RVIZ=1

if [ "$LAUNCH_RVIZ" -eq 1 ]; then
    roslaunch rs-pcl2 rviz.launch
fi

wait
