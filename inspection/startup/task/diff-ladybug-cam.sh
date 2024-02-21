#!/bin/bash

###### DESCRIPTION ######
### Usage: Turn on differential inspection system
### Precaution: 
######
#!/bin/bash

### ARGUMENTS ###
CAM_A_ON=1 # Set to 1 to turn on, 0 to turn off
CAM_B_ON=0
LADYBUG_ON=1
###

# Function to run a script with a delay if its corresponding flag is set to 1
run_script() {
  local script=$1
  local flag=$2
  local delay=$3

  if [ "$flag" -eq 1 ]; then
    (sleep $delay; ./"$script") &
  fi
}

# Initialize delay
DELAY=0

# Run the scripts with a delay if they are turned on
run_script "subtesk/diff-cam-a.sh" $CAM_A_ON $DELAY
DELAY=$(($DELAY + 1))

run_script "subtesk/diff-cam-b.sh" $CAM_B_ON $DELAY
DELAY=$(($DELAY + 1))

run_script "subtesk/diff-ladybug.sh" $LADYBUG_ON $DELAY

wait
