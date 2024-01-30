#!/bin/bash
# Stop on any error
set -e

# Update package list
sudo apt update

# rosdep check --from-paths . --ignore-src --rosdistro noetic
# rosdep install --from-paths . --ignore-src --rosdistro noetic -y

# Build extraction-ws workspace
cd /home/extraction-ws
catkin_make

# Keep the container running
tail -f /dev/null
