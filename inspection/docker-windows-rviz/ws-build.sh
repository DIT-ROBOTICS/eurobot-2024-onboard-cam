#!/bin/bash
# Stop on any error
set -e

# Update package list
sudo apt update
sudo apt install -y pcl-tools

# rosdep check --from-paths . --ignore-src --rosdistro noetic
# rosdep install --from-paths . --ignore-src --rosdistro noetic -y

# Build realsense-ws workspace
cd /home/realsense-ws
catkin_make

# Build extraction-ws workspace
cd /home/extraction-ws
catkin_make

# Keep the container running
tail -f /dev/null
