#!/bin/bash

###### DESCRIPTION ######
### Usage: differential inspection system
### Precaution: Run realsense-cam-X.sh First
######

### ARGUMENTS ###
LAUNCH_RVIZ=1 # 1 to launch rviz, otherwise don't
###

ROS_DISTRO=noetic
source /opt/ros/$ROS_DISTRO/setup.bash

cd /home/extraction-ws
source devel/setup.bash

# Launch differential
roslaunch diff-rs-pcl2 main-b.launch &

if [ "$LAUNCH_RVIZ" -eq 1 ]; then
    roslaunch diff-rs-pcl2 rviz-marker-b.launch
fi

wait