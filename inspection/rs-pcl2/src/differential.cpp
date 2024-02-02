#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>

class PointCloudFilter {
public:
    PointCloudFilter(ros::NodeHandle& nh) {
        double filter_low, filter_high;
        
        // default value
        nh.param("filter_low", filter_low, -0.5);  
        nh.param("filter_high", filter_high, 0.5); 

        // set by param
        pass_.setFilterFieldName("y");
        pass_.setFilterLimits(filter_low, filter_high);

        sub_ = nh.subscribe("/input", 1, &PointCloudFilter::cloudCallback, this);
        pub_ = nh.advertise<sensor_msgs::PointCloud2>("/output", 1);
    }

    void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg) {
        // tf ROS msg to PCL data
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
        pcl::fromROSMsg(*cloud_msg, *cloud);

        // apply filter
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>());
        pass_.setInputCloud(cloud);
        pass_.filter(*cloud_filtered);

        // filted PCL tf back to ROS
        sensor_msgs::PointCloud2 output;
        pcl::toROSMsg(*cloud_filtered, output);
        output.header = cloud_msg->header; 
        pub_.publish(output);
    }

private:
    ros::Subscriber sub_;
    ros::Publisher pub_;
    pcl::PassThrough<pcl::PointXYZRGB> pass_;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "point_cloud_filter");
    ros::NodeHandle nh;

    PointCloudFilter filter(nh);

    ros::spin();

    return 0;
}
