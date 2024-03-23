#!/bin/bash

cd ~/onboard_ws
source devel/setup.bash
#rostopic pub /robot/startup/ready_signal geometry_msgs/PointStamped "{'point': {'x': 5.0}}"
rosservice call /robot/onboard_cam "signal: 1"