#include "diff-cube.h"

namespace cube {
    double x_low_, x_high_, y_low_, y_high_, z_low_, z_high_;

    void initialize(ros::NodeHandle& nh) {
        nh.getParam("/diff/filter_high_x", x_high_);
        nh.getParam("/diff/filter_low_x", x_low_);
        nh.getParam("/diff/filter_high_y", y_high_);
        nh.getParam("/diff/filter_low_y", y_low_);
        nh.getParam("/diff/filter_high_z", z_high_);
        nh.getParam("/diff/filter_low_z", z_low_);
    }

    void filterPointCloud(const sensor_msgs::PointCloud2ConstPtr& cloud_msg, sensor_msgs::PointCloud2& output) {
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

        pcl::toROSMsg(*cloud_filtered, output);
    }
}
