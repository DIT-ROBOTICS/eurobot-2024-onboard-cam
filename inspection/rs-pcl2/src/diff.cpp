#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include "diff-cube.h" // Include the cube header

class PointCloudFilter {
public:
    PointCloudFilter(ros::NodeHandle& nh) {
        cube::initialize(nh); // Initialize cubes with parameters

        sub_ = nh.subscribe("/input", 1, &PointCloudFilter::cloudCallback, this);
        pub_ = nh.advertise<sensor_msgs::PointCloud2>("/output", 1);
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

    ros::spin();

    return 0;
}
