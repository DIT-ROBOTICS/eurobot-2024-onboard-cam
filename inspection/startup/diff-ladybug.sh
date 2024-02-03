#!/bin/bash

###### DESCRIPTION ######
### Usage: differential inspection system
### Precaution: 
######

ROS_DISTRO=noetic
source /opt/ros/$ROS_DISTRO/setup.bash

cd /home/extraction-ws
source devel/setup.bash

# differential
roslaunch rs-pcl2 diff.launch
roslaunch rs-pcl2 diff-rviz.launch
