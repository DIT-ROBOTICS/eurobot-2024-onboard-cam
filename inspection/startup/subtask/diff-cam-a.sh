#!/bin/bash

###### DESCRIPTION ######
### Usage: turn on camera 1
### Precaution: 
######

### ARGUMENTS ###
# Default values for parameters
camera="diff_cam_A"
serial_no="215222079777"
use_filters=true
filters="spatial,temporal,pointcloud"
###

# Source the ROS setup script
ROS_DISTRO=noetic
source /opt/ros/$ROS_DISTRO/setup.bash

# Parse command line arguments for camera and serial_no, and use_filters
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -c|--camera) camera="$2"; shift ;;
        -s|--serial-no) serial_no="$2"; shift ;;
        -f|--use-filters) use_filters=true ;;
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done

cd /home/realsense-ws
source devel/setup.bash

# Conditionally add filters to the launch command
if $use_filters; then
    roslaunch realsense2_camera rs_camera.launch camera:=$camera serial_no:=$serial_no filters:=$filters
else
    roslaunch realsense2_camera rs_camera.launch camera:=$camera serial_no:=$serial_no
fi
