#ifndef _DIFF_DBSCAN_H_
#define _DIFF_DBSCAN_H_

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/surface/convex_hull.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/search/kdtree.h>
#include <pcl/segmentation/extract_clusters.h>
#include <visualization_msgs/MarkerArray.h>
#include <Eigen/Core>
#include <pcl/common/centroid.h>
#include <pcl/common/common.h>
#include <pcl/common/pca.h>


namespace dbscan {
    void initialize(ros::NodeHandle& nh);
    void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg);
    void clusterAndVisualize(const sensor_msgs::PointCloud2ConstPtr& cloud_msg);
    void analyzeAndPrintObjectInfo(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr& cloud_cluster);
    void addFilledConvexHullMarkersTo(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr& cloud_cluster,
            visualization_msgs::MarkerArray& marker_array, int cluster_id, const std::string& frame_id);
    void addBoundingBoxMarker(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr& cloud_cluster,
            visualization_msgs::MarkerArray& marker_array, int cluster_id, const std::string& frame_id);
    void clearPreviousMarkers();
}

#endif // _DIFF_DBSCAN_H_
