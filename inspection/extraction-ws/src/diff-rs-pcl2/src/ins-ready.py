#!/usr/bin/env python

import rospy
from std_srvs.srv import SetBool, SetBoolRequest

def send_ready_signal():
    rospy.wait_for_service('/robot/objects/ladybug_activate')
    try:
        activate_service = rospy.ServiceProxy('/robot/objects/ladybug_activate', SetBool)
        request = SetBoolRequest()
        request.data = True 
        response = activate_service(request)
        rospy.loginfo("Response: %s", response.message)
    except rospy.ServiceException as e:
        rospy.logerr("Service call failed: %s", e)

if __name__ == '__main__':
    rospy.init_node('ready_signal_client')
    send_ready_signal()
