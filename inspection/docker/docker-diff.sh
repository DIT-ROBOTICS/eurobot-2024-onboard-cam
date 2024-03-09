#!/bin/bash

find /home/vision/pomelo925/eurobot-2024-vision-main -type f -name "*.sh" -exec chmod +x {} \;

export DISPLAY=localhost:10.0
docker compose -p inspection up -f compose-diff-build.yml

#docker compose down the container and run the below one

docker compose -p inspection up -f compose-diff-run.yml -d