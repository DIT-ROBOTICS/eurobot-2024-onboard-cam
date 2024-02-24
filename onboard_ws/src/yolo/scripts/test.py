import pyrealsense2 as rs
import numpy as np
import cv2
import logging


# Configure depth and color streams...
# ...from Camera 1
pipeline_1 = rs.pipeline()
config_1 = rs.config()
config_1.enable_device('215222079777')
config_1.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
config_1.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
profile_1 = pipeline_1.start(config_1)
align_1 = rs.align(rs.stream.color)
intr_1 = profile_1.get_stream(rs.stream.color).as_video_stream_profile().get_intrinsics()

# ...from Camera 2
pipeline_2 = rs.pipeline()
config_2 = rs.config()
config_2.enable_device('215322071267')
config_2.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
config_2.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
profile_2 = pipeline_2.start(config_2)
align_2 = rs.align(rs.stream.color)
intr_2 = profile_2.get_stream(rs.stream.color).as_video_stream_profile().get_intrinsics()

frames_1 = pipeline_1.wait_for_frames()
aligned_frames_1 = align_1.process(frames_1)
color_frame_1 = aligned_frames_1.get_color_frame()
depth_frame_1 = aligned_frames_1.get_depth_frame()