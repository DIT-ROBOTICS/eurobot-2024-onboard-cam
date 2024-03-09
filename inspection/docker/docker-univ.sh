#!/bin/bash

find /home/vision/pomelo925/eurobot-2024-vision-main/onboard/inspection -type f -name "*.sh" -exec chmod +x {} \;

export DISPLAY=localhost:10.0

docker compose -p inspection -f compose-build.yml -p vision-inspection-universal up
docker compose -p vision-inspection-universal down --volumes --remove-orphans

docker compose -p inspection -f compose-run-univ.yml -p vision-inspection-universal up -d