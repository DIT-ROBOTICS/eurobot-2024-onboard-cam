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


sudo apt update

# rosdep check --from-paths . --ignore-src --rosdistro noetic
# rosdep install --from-paths . --ignore-src --rosdistro noetic -y

# Build extraction-ws workspace
cd /home/extraction-ws
catkin_make

# Keep the container running
tail -f /dev/null