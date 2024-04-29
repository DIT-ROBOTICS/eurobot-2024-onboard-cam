#!/bin/bash

###### DESCRIPTION ######
### Usage: 
### Precaution:  Ensure that scripts are executable (`chmod +x <script>`)
### 

/home/startup/diff/task/diff-cam-b.sh &
/home/startup/diff/task/diff-ladybug-b.sh &
/home/startup/diff/task/diff-safety-b.sh &
wait
echo "All scheduled scripts have completed."