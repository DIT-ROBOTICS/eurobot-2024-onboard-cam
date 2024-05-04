#!/bin/bash

###### DESCRIPTION ######
### Usage: Turn on universal inspection system
### Precaution: Ensure that scripts are executable (`chmod +x <script>`)
### 

### ARGUMENTS ###
CAM_A_SYSTEM_ON=1 # Set to 1 to turn on, 0 to turn off
CAM_B_SYSTEM_ON=1
###

run_script_with_delay() {
    script_path=$1
    delay=$2

    "$script_path" & sleep "$delay"
}

if [ "$CAM_A_SYSTEM_ON" -eq 1 ]; then
    echo "Starting universal inspection system for Camera A..."
    run_script_with_delay "/home/startup/univ/task/univ-cam-a.sh" 1
    run_script_with_delay "/home/startup/univ/task/univ-ladybug-a.sh" 1
fi

if [ "$CAM_B_SYSTEM_ON" -eq 1 ]; then
    echo "Starting universal inspection system for Camera B..."
    run_script_with_delay "/home/startup/univ/task/univ-cam-b.sh" 1
    run_script_with_delay "/home/startup/univ/task/univ-ladybug-b.sh" 1
fi

run_script_with_delay "/home/startup/univ/task/univ-safety-ab.sh" 1

wait
echo "All scheduled scripts have completed."