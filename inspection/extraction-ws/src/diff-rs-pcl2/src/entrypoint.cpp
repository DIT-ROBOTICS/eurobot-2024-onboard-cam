#include "ros/ros.h"
#include "geometry_msgs/PointStamped.h"
#include "std_srvs/SetBool.h" 

bool flag = false;

bool readySignalCallback(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res){
    ROS_INFO("Ready signal successfully received.");
    res.success = true;
    res.message = "Ready signal set to True.";
    //if get ready signal, activate ladybug
    if(req.data == true){
        flag = true;
    }
    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "ready_signal_activate");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("/robot/objects/ladybug_activate", readySignalCallback);
    ROS_INFO("waiting for activate...");

    while(ros::ok()){
        ros::spinOnce();
        if(flag){
          system("/home/startup/diff/diff-inspection.sh");
        }
    }
    return 0;
}
