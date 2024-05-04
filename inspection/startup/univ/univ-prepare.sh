#!/bin/bash

echo "[UNIV][INSPECTION] Waiting for ready signal ..."

cd /home/extraction-ws
source devel/setup.bash
rosrun univ-rs-pcl2 U-entrypoint