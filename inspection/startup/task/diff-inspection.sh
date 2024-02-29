#!/bin/bash

###### DESCRIPTION ######
### Usage: Turn on differential inspection system
### Precaution: Ensure that scripts are executable (`chmod +x <script>`)
### 

### ARGUMENTS ###
CAM_A_ON=1 # Set to 1 to turn on, 0 to turn off
CAM_B_ON=0
LADYBUG_ON=1
###


run_script() {
  local script=$1
  local flag=$2
  local delay=$3

  if [ "$flag" -eq 1 ]; then
    (sleep $delay; "$script") &
  fi
}

DELAY=0
run_script "/home/startup/subtask/diff-cam-a.sh" $CAM_A_ON $DELAY
DELAY=$(($DELAY + 1))
run_script "/home/startup/subtask/diff-cam-b.sh" $CAM_B_ON $DELAY
DELAY=$(($DELAY + 1))
run_script "/home/startup/subtask/diff-ladybug.sh" $LADYBUG_ON $DELAY

wait
echo "All scheduled scripts have completed."