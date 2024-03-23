#!/usr/bin/python3
#Vision
from ultralytics import YOLO
import cv2

#ROS
import rospy
from yolo.msg import yolomsg
from sensor_msgs.msg import Image
from geometry_msgs.msg import PointStamped
from yolo.srv import signal, signalResponse

#Img msg parser to cv
from cv_bridge import CvBridge

#Other tools 
import math
import numpy as np
import pyrealsense2 as rs

FRONT_CAMERA_ID = '215322071267'
BACK_CAMERA_ID = '215222079777'
XOFFSET = 0.014382474 # x distance with machine center
ZOFFSET = 0.099894668 # Z distance with machine center
THETA = 0 # camera depression angle in degree
WIN_WIDTH, WIN_HEIGHT = 640, 480 # GUI window size
GUI = True

class Node:
    def __init__(self):
        ###Adding Param

        #start_signal_flag
        self.group = 2
        self.READY_SIGNAL = None
        # self.START_SIGNAL = 0
        self.WATCH_SIGNAL = 0
        self.KILL_SIGNAL = 0

        #CvBridge
        self.bridge = CvBridge()
        #YOLO
        self.model = YOLO("/root/onboard_ws/src/yolo/weight/onboard_cam_low.pt")
        self.model.fuse() # Fuse for speed
        self.result_img = None

        #Publisher 
        rospy.init_node("vison_node")
        self.pub = rospy.Publisher("/robot/objects/front_plants", yolomsg, queue_size=10)
        self.bgrm_pub = rospy.Publisher("/yolo/bgrm", Image, queue_size=10)
        self.result_pub = rospy.Publisher("/yolo/result", Image, queue_size=10)

        #Subscriber
        # self.col1_msg = None
        # self.dep1_msg = None
        # self.sub_col1 = rospy.Subscriber("/cam1/color/image_raw", Image, self.col_callback1)
        # self.sub_dep1 = rospy.Subscriber("/cam1/aligned_depth_to_color/image_raw", Image, self.dep_callback1) 
        #self.sub_coln = rospy.Subscriber("/camn/color/image_raw", Image, self.col_callbackn)
        #self.sub_depn = rospy.Subscriber("/camn/depth/image_rect_raw", Image, self.dep_callbackn) 
        self.sub_ready = rospy.Subscriber("/robot/startup/ready_signal", PointStamped, self.ready_callback)



        # #Server
        # rospy.Service("/robot/startup/ready_signal", signal, self.ready_callback)
        # rospy.Service("/robot/start_signal", signal, self.start_callback)
        # rospy.Service("/robot/skip_signal", signal, self.stop_callback)
        # rospy.Service("/robot/kill_signal", signal, self.kill_callback)

        rospy.Service("/robot/onboard_cam", signal, self.onboard_cam_callback)

        #client
        def client(group):
            rospy.wait_for_service("/robot/startup/ready_signal")
            try:
                ready_client = rospy.ServiceProxy("/robot/startup/ready_signal",ready)
                resp = ready_client(group)
            except rospy.ServiceException:
                rospy.logwarn("Service call failde")

    # def col_callback1(self, msg):
    #     self.col1_msg = msg
    # def dep_callback1(self, msg):
    #     self.dep1_msg = msg

    def ready_callback(self, msg):
        if msg.point.x is not None:
            self.READY_SIGNAL = msg.point.x
            rospy.loginfo("We are ready")

    # def start_callback(self, req):
    #     if req.ready is True:
    #         self.START_SIGNAL = req.ready
    #         return signalResponse(True)

    # def stop_callback(self, req):
    #     if req.ready is True:
    #         self.SKIP_SIGNAL = req.ready
    #         return signalResponse(True)
    #     if req.ready is False:
    #         self.SKIP_SIGNAL = req.ready
    #         return signalResponse(False)

    # def kill_callback(self, req):
    #     if req.ready is True:
    #         self.KILL_SIGNAL = req.ready
    #         return signalResponse(True)

    def onboard_cam_callback(self, req):
        # if req.signal == 1:
        #     self.START_SIGNAL = req.signal
        #     return signalResponse(True)
        if req.signal == 0:
            self.WATCH_SIGNAL = req.signal
            return signalResponse(True)
        if req.signal == 1:
            self.WATCH_SIGNAL = req.signal
            return signalResponse(True)
        if req.signal == 2:
            self.KILL_SIGNAL = req.signal
            return signalResponse(True)
        else:
            return signalResponse(False)

    '''
    def col_callbackn(self, msg):
        self.col1_msg = msg
    def dep_callbackn(self, msg):
        self.dep1_msg = msg
    '''
    def bg_removal(self, col_msg:Image, dep_msg:Image):
        """
        Input:
        col_msg : 'Image'-- RGB
        dep_msg : 'Image'-- Z16
        
        Return:
        bgrm_img : 'Image' -- RGB
        """
        # #Convert col_msg
        # cv_col1_img = self.bridge.imgmsg_to_cv2(col1_msg, desired_encoding = "bgr8")
        np_col_img = np.asanyarray(col_msg.get_data())
        #coln_image = CvBridge.imgmsg_to_cv2(coln_msg, desired_encoding = 'bgr8')

        # #Convert dep_msg
        # cv_dep1_img = self.bridge.imgmsg_to_cv2(dep1_msg, desired_encoding = "passthrough")
        np_dep_img = np.asanyarray(dep_msg.get_data())

        #3d depth image to match bgr color image #stack 1 dim into 3
        dep_3d_img = np.dstack((np_dep_img, np_dep_img, np_dep_img)) 

        #bg removal 
        grey = 153
        bgrm_img = np.where((dep_3d_img > 450) | (np.isnan(dep_3d_img)), grey, np_col_img)
        return bgrm_img

    def yolo(self):
        if rospy.is_shutdown() == False:
            #bg removal
            color_img_1, depth_img_1, color_img_2, depth_img_2 = realsense.wait_for_frames()
            bgrm_img_1 = self.bg_removal(color_img_1, depth_img_1)
            bgrm_img_2 = self.bg_removal(color_img_2, depth_img_2)
            #self.bgrm_pub.publish(self.bridge.cv2_to_imgmsg(bgrm_img, encoding="bgr8"))

            #YOLO detection
            results_1 = self.model(source = bgrm_img_1)
            results_2 = self.model(source = bgrm_img_2)

            plantmsg = yolomsg()
            plantmsg.x = []
            plantmsg.y = []
            
            for r in results_1:
                # self.result_img = object.plot()
                # self.result_pub.publish(self.bridge.cv2_to_imgmsg(self.result_img, encoding="bgr8")) 
                boxes = r.boxes

                for box in boxes:
                    x1, y1, x2, y2 = map(int, box.xyxy[0])
                    x, y = int((x1 + x2) / 2), int(y1 / 4 + y2 * 3 / 4)
                    depth = depth_img_1.get_distance(x, y)

                    Xtarget, Ztarget = self.transform_coordinates_1(depth, x, y, realsense.intr_1, THETA)
                    plantmsg.x.append(Xtarget)
                    plantmsg.y.append(Ztarget)

                    if GUI is True:
                     self.cv2_draw(bgrm_img_1, x, y, x1, y1, x2, y2, Xtarget, Ztarget)

            for r in results_2:
                # self.result_img = object.plot()
                # self.result_pub.publish(self.bridge.cv2_to_imgmsg(self.result_img, encoding="bgr8")) 
                boxes = r.boxes

                for box in boxes:
                    x1, y1, x2, y2 = map(int, box.xyxy[0])
                    x, y = int((x1 + x2) / 2), int(y1 / 4 + y2 * 3 / 4)
                    depth = depth_img_2.get_distance(x, y)

                    Xtarget, Ztarget = self.transform_coordinates_2(depth, x, y, realsense.intr_2, THETA)
                    plantmsg.x.append(Xtarget)
                    plantmsg.y.append(Ztarget)

                    if GUI is True:
                        self.cv2_draw(bgrm_img_2, x, y, x1, y1, x2, y2, Xtarget, Ztarget)
                    
            self.pub.publish(plantmsg)
            return bgrm_img_1, bgrm_img_2

    def transform_coordinates_1(self, depth, x, y, intr, theta):
        Xtemp = depth * (x - intr.ppx) / intr.fx
        #Ytemp = depth * (y - intr.ppy) / intr.fy
        Ztemp = depth

        Xtarget = Xtemp + XOFFSET
        Ztarget = Ztemp*math.cos(math.radians(theta)) + ZOFFSET

        #fit with main system
        X_target = Ztarget
        Z_target = -Xtarget

        return X_target, Z_target
    
    def transform_coordinates_2(self, depth, x, y, intr, theta):
        Xtemp = depth * (x - intr.ppx) / intr.fx
        #Ytemp = depth * (y - intr.ppy) / intr.fy
        Ztemp = depth

        Xtarget = Xtemp + XOFFSET
        Ztarget = Ztemp*math.cos(math.radians(theta)) + ZOFFSET

        #back camera
        Xtarget = -Xtarget
        Ztarget = -Ztarget

        #fit with main system
        X_target = Ztarget
        Z_target = -Xtarget

        return X_target, Z_target
    
    def cv2_draw(self, img, x, y, x1, y1, x2, y2, Xtarget, Ztarget):
        cv2.rectangle(img, (x1, y1), (x2, y2), (255, 255, 255), 2)
        cv2.circle(img, (x, y), 3, (0, 0, 255), 2)
        cv2.putText(img, "({:.3f}, {:.3f})".format(Xtarget, Ztarget), (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
    
class RealsenseCamera:
    def __init__(self):
        self.pipeline_1 = rs.pipeline()
        self.config_1 = rs.config()
        self.config_1.enable_device(FRONT_CAMERA_ID) #camera 1 (the front)
        self.config_1.enable_stream(rs.stream.color, WIN_WIDTH, WIN_HEIGHT, rs.format.bgr8, 30)
        self.config_1.enable_stream(rs.stream.depth, WIN_WIDTH, WIN_HEIGHT, rs.format.z16, 30)
        self.profile_1 = self.pipeline_1.start(self.config_1)
        self.align_1 = rs.align(rs.stream.color)
        self.intr_1 = self.profile_1.get_stream(rs.stream.color).as_video_stream_profile().get_intrinsics()

        self.pipeline_2 = rs.pipeline()
        self.config_2 = rs.config()
        self.config_2.enable_device(BACK_CAMERA_ID) #camera 2 (the back)
        self.config_2.enable_stream(rs.stream.color, WIN_WIDTH, WIN_HEIGHT, rs.format.bgr8, 30)
        self.config_2.enable_stream(rs.stream.depth, WIN_WIDTH, WIN_HEIGHT, rs.format.z16, 30)
        self.profile_2 = self.pipeline_2.start(self.config_2)
        self.align_2 = rs.align(rs.stream.color)
        self.intr_2 = self.profile_2.get_stream(rs.stream.color).as_video_stream_profile().get_intrinsics()

    def wait_for_frames(self):
        frames_1 = self.pipeline_1.wait_for_frames()
        aligned_frames_1 = self.align_1.process(frames_1)
        color_frame_1 = aligned_frames_1.get_color_frame()
        depth_frame_1 = aligned_frames_1.get_depth_frame()

        frames_2= self.pipeline_2.wait_for_frames()
        aligned_frames_2 = self.align_2.process(frames_2)
        color_frame_2 = aligned_frames_2.get_color_frame()
        depth_frame_2 = aligned_frames_2.get_depth_frame()

        return color_frame_1, depth_frame_1, color_frame_2, depth_frame_2


if __name__ == "__main__":
    
    vision_node = Node()

    # #wait for ready signal
    # while not rospy.is_shutdown():
    #     if vision_node.READY_SIGNAL is None:
    #         rospy.loginfo("waiting for ready signal")
    #         rospy.sleep(1.)
    #     else:
    #         vision_node.client(vision_node.group)
    #         break

    realsense = RealsenseCamera()

    # #wait for start signal
    # while not rospy.is_shutdown():
    #     if vision_node.START_SIGNAL == 0:
    #         rospy.loginfo("waiting for start signal")
    #         rospy.sleep(1.)
    #     elif vision_node.START_SIGNAL == 1:
    #         break
    
    if GUI is True:
        cv2.namedWindow('Front Camera', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Front Camera', WIN_WIDTH, WIN_HEIGHT)
        cv2.namedWindow('Back Camera', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Back Camera', WIN_WIDTH, WIN_HEIGHT)

    try:
        while not rospy.is_shutdown():

            #kill the node
            if vision_node.KILL_SIGNAL == 2:
                break

            #skip the main function or not
            if vision_node.WATCH_SIGNAL == 1:
                pass
            if vision_node.WATCH_SIGNAL == 0:
                continue

            img_withbox_1, img_withbox_2 = vision_node.yolo()

            if GUI is True:
                cv2.imshow('Front Camera', np.array(img_withbox_1, dtype = np.uint8 ))
                cv2.imshow('Back Camera', np.array(img_withbox_2, dtype = np.uint8 ))
                if cv2.waitKey(1) == ord('q'):
                    break

    except KeyboardInterrupt:
        pass
    finally:
        #cv2.destroyAllWindows()
        pass
