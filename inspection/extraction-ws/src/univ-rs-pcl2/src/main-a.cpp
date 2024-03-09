#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#include "voxelgrid-cube.h" 
#include "dbscan-cluster.h"

class PointCloudFilter {
public:
    cube cube_instance;

    PointCloudFilter(ros::NodeHandle& nh, const std::string& param_prefix) {
        sub_ = nh.subscribe("univ_A/input", 1, &PointCloudFilter::cloudCallback, this);
        pub_ = nh.advertise<sensor_msgs::PointCloud2>("cube_A/output", 1);

        cube_instance.initialize(nh, param_prefix); 
    }

    void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg) {
        sensor_msgs::PointCloud2 output;
        cube_instance.filterPointCloud(cloud_msg, output);
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

    // Fetch the namespace prefix from parameters
    std::string isA;
    nh.param<std::string>("vision/cam_prefix", isA, "A"); 

    std::string param_prefix;
    if(isA == "A") param_prefix = "A";
    else param_prefix = "B";

    PointCloudFilter filter(nh, param_prefix);

    dbscan dbscan_instance;
    dbscan_instance.initialize(nh, param_prefix); 

    ros::spin();
    return 0;
}
