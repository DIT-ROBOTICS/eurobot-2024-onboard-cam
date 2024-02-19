#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#include "diff-cube.h" 
#include "diff-dbscan.h"

class PointCloudFilter {
public:
    PointCloudFilter(ros::NodeHandle& nh) {
        cube::initialize(nh); // Initialize cubes with parameters

        sub_ = nh.subscribe("diff/input", 1, &PointCloudFilter::cloudCallback, this);
        pub_ = nh.advertise<sensor_msgs::PointCloud2>("cube/output", 1);
    }

    void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg) {
        sensor_msgs::PointCloud2 output;
        cube::filterPointCloud(cloud_msg, output); // Delegate filtering to cube
        output.header = cloud_msg->header;
        pub_.publish(output);
    }

private:
    ros::Subscriber sub_;
    ros::Publisher pub_;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "point_cloud_filter");
    ros::NodeHandle nh;

    PointCloudFilter filter(nh);

    dbscan dbscan_instance;
    dbscan_instance.initialize(nh);
    
    ros::spin();

    return 0;
}
