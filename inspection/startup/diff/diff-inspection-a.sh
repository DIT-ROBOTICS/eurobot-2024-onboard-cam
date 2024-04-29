#!/bin/bash

###### DESCRIPTION ######
### Usage: 
### Precaution:  Ensure that scripts are executable (`chmod +x <script>`)
### 

/home/startup/diff/task/diff-cam-a.sh &
/home/startup/diff/task/diff-ladybug-a.sh &
/home/startup/diff/task/diff-safety-a.sh &
wait
echo "All scheduled scripts have completed."