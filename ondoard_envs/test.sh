#!/bin/bash

cd ~/onboard_ws
source devel/setup.bash
rosservice call /robot/startup/ready_signal "ready: true"
rosservice call /robot/start_signal "ready: true"