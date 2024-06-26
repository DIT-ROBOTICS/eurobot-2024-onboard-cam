#!/bin/bash
docker compose -p vision-inspection-universal down --volumes --remove-orphans

find /home/vision/pomelo925/eurobot-2024-vision-main/onboard/inspection -type f -name "*.sh" -exec chmod +x {} \;

export DISPLAY=localhost:10.0

docker compose -p vision-inspection-universal -f compose-build.yml up
docker compose -p vision-inspection-universal down --volumes --remove-orphans

docker compose -p vision-inspection-universal -f compose-run-univ.yml up -d