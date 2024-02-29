#!/bin/bash

echo "[DIFF][INSPECTION] Waiting for ready signal ..."

cd /home/extraction-ws
source devel/setup.bash
rosrun rs-pcl2 entrypoint