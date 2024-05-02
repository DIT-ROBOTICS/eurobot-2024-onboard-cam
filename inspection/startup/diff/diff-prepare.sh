#!/bin/bash

echo "[DIFF][INSPECTION] Waiting for ready signal ..."

cd /home/extraction-ws
source devel/setup.bash

roslaunch diff-rs-pcl2 diff-prepare.launch