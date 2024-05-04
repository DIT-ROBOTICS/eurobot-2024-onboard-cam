#ifndef _VOXELGRID_CUBE_H_
#define _VOXELGRID_CUBE_H_

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>

#include <pcl/filters/voxel_grid.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>


class cube {
public:
    double x_low_, x_high_, y_low_, y_high_, z_low_, z_high_, distance_threshold_, leaf_size_;
    int max_iterations_;
    
    void initialize(ros::NodeHandle& nh, const std::string& param_prefix);
    void filterPointCloud(const sensor_msgs::PointCloud2ConstPtr& cloud_msg, sensor_msgs::PointCloud2& output);
};


#endif // _VOXELGRID_CUBE_H_
