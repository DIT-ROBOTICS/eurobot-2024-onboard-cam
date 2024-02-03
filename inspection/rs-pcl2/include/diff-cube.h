#ifndef _CUBE_H_
#define _CUBE_H_

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>


namespace cube {
    void initialize(ros::NodeHandle& nh);
    void filterPointCloud(const sensor_msgs::PointCloud2ConstPtr& cloud_msg, sensor_msgs::PointCloud2& output);
}

#endif // _CUBE_H_
