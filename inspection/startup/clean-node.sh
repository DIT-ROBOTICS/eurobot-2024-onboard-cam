#!/bin/bash

rosnode kill /diff_cam_A/realsense2_camera_manager
rosnode kill /diff_cam_B/realsense2_camera_manager
rosnode kill /univ_cam_A/realsense2_camera_manager
rosnode kill /univ_cam_B/realsense2_camera_manager