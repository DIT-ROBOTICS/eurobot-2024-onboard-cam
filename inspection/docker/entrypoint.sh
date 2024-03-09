#!/bin/bash
# Stop on any error
set -e

# Load the shell's source file, if it exists.
if [ -f ~/.bashrc ]; then
    source ~/.bashrc
fi

# Source the ROS setup script
ROS_DISTRO=noetic
source /opt/ros/$ROS_DISTRO/setup.bash

tail -f /dev/null