#include "ros/ros.h"
#include "geometry_msgs/PointStamped.h"
#include "std_srvs/SetBool.h" 

ros::ServiceClient client;


// Callback for the topic subscriber
void readySignalCallback(const geometry_msgs::PointStamped::ConstPtr& msg) {
  std_srvs::SetBool srv;
  srv.request.data = true; 

  // Check frame_id to see if we should proceed with the service ca
  if (msg->header.frame_id == "inspection") {
    if (client.call(srv)) system("/home/startup/univ/univ-inspection.sh");
    else ROS_ERROR("Failed to call service.");
  } 
  
  else {
    srv.request.data = false; 
    if (!client.call(srv)) ROS_ERROR("Failed to call service.");
  }

  ros::shutdown();
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "ready_signal_processor");
    ros::NodeHandle nh;

    client = nh.serviceClient<std_srvs::SetBool>("/robot/startup/ready_signal");
    ros::Subscriber sub = nh.subscribe("/robot/startup/ready_signal", 1000, readySignalCallback);

    ros::spin();

    return 0;
}
