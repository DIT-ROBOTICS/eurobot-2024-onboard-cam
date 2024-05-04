/**
 *
 * @file safety-ab.cpp
 * @brief
 * Voxel grid cube class for filtering point cloud data within specified boundaries. 
 * The class initializes filter boundaries based on parameters provided by the ROS node, 
 * and filters point cloud data accordingly using pass-through filters along the X, Y, and Z axes.
 * 
 * Functionalities :
 * - Initializing filter boundaries based on ROS parameters
 * - Filtering point cloud data along the X, Y, and Z axes using pass-through filters
 *
 * @code{.unparsed}
 *      _____
 *     /  /::\       ___           ___
 *    /  /:/\:\     /  /\         /  /\
 *   /  /:/  \:\   /  /:/        /  /:/
 *  /__/:/ \__\:| /__/::\       /  /:/
 *  \  \:\ /  /:/ \__\/\:\__   /  /::\
 *   \  \:\  /:/     \  \:\/\ /__/:/\:\
 *    \  \:\/:/       \__\::/ \__\/  \:\
 *     \  \::/        /__/:/       \  \:\
 *      \__\/         \__\/         \__\/
 * @endcode
 *
 * @author pomelo925 (yoseph.huang@gmail.com)
 * @version 2.1
 * @date 2024-03-27
 *
 */

#include "voxelgrid-cube.h"

extern double x_low_, x_high_, y_low_, y_high_, z_low_, z_high_, distance_threshold_, leaf_size_;
extern int max_iterations_;

void cube::initialize(ros::NodeHandle& nh, const std::string& param_prefix) {
    nh.getParam("univ_" + param_prefix + "/filter_high_x", x_high_);
    nh.getParam("univ_" + param_prefix + "/filter_low_x", x_low_);
    nh.getParam("univ_" + param_prefix + "/filter_high_y", y_high_);
    nh.getParam("univ_" + param_prefix + "/filter_low_y", y_low_);
    nh.getParam("univ_" + param_prefix + "/filter_high_z", z_high_);
    nh.getParam("univ_" + param_prefix + "/filter_low_z", z_low_);

    nh.getParam("univ_" + param_prefix + "/leaf_size", leaf_size_);
    nh.getParam("univ_" + param_prefix + "/max_iterations", max_iterations_);
    nh.getParam("univ_" + param_prefix + "/distance_threshold", distance_threshold_);
}

void cube::filterPointCloud(const sensor_msgs::PointCloud2ConstPtr& cloud_msg, sensor_msgs::PointCloud2& output) {
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
    pcl::fromROSMsg(*cloud_msg, *cloud);

    pcl::PassThrough<pcl::PointXYZRGB> pass;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>());

    // Filter X
    pass.setInputCloud(cloud);
    pass.setFilterFieldName("x");
    pass.setFilterLimits(x_low_, x_high_);
    pass.filter(*cloud_filtered);

    // Filter Y
    pass.setInputCloud(cloud_filtered);
    pass.setFilterFieldName("y");
    pass.setFilterLimits(y_low_, y_high_);
    pass.filter(*cloud_filtered);

    // Filter Z
    pass.setInputCloud(cloud_filtered);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(z_low_, z_high_);
    pass.filter(*cloud_filtered);

    // Down sampling
    pcl::VoxelGrid<pcl::PointXYZRGB> voxel_grid;
    voxel_grid.setInputCloud(cloud_filtered);
    voxel_grid.setLeafSize(leaf_size_, leaf_size_, leaf_size_); 
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr downsampled_cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    voxel_grid.filter(*downsampled_cloud);

    // Plane Segment
    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
    pcl::SACSegmentation<pcl::PointXYZRGB> seg;
    seg.setOptimizeCoefficients(true);
    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setMaxIterations(max_iterations_);
    seg.setDistanceThreshold(distance_threshold_);
    seg.setInputCloud(downsampled_cloud);
    seg.segment(*inliers, *coefficients);

    pcl::ExtractIndices<pcl::PointXYZRGB> extract;
    extract.setInputCloud(downsampled_cloud);
    extract.setIndices(inliers);
    extract.setNegative(true);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_without_plane(new pcl::PointCloud<pcl::PointXYZRGB>);
    extract.filter(*cloud_without_plane);

    pcl::toROSMsg(*cloud_without_plane, output);
}
