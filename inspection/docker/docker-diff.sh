#!/bin/bash
docker compose -p vision-inspection-differential down --volumes --remove-orphans

find /home/vision/pomelo925/eurobot-2024-vision-main/onboard/inspection -type f -name "*.sh" -exec chmod +x {} \;

export DISPLAY=localhost:10.0

docker compose -p inspection -f compose-build.yml -p vision-inspection-differential up
docker compose -p vision-inspection-differential down --volumes --remove-orphans

docker compose -p inspection -f compose-run-diff.yml -p vision-inspection-differential up -d