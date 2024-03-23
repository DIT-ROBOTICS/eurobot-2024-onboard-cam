#!/bin/bash

cd ~/onboard_ws
# catkin_make

# if [ $? -eq 0 ]; then
#     . devel/setup.bash
#     roscore &
#     cd src/yolo/scripts
#     export DISPLAY="localhost:10.0"
#     python3 multinewnew_v8.py
# else
#     echo "catkin_make failed, unable to continue."
# fi

. devel/setup.bash
roscore &
cd src/yolo/scripts
export DISPLAY="localhost:10.0"
python3 multinewnew_v8.py