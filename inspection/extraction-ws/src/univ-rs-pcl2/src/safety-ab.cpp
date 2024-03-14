#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <vector>

class SafetyFilter {
public:
    SafetyFilter() : nh_("~"), univ_A_state_(false), univ_B_state_(false) {
        // Initialize subscribers
        sub_univ_A_ = nh_.subscribe("/univ_A/ladybug/safe", 10, &SafetyFilter::diffACallback, this);
        sub_univ_B_ = nh_.subscribe("/univ_B/ladybug/safe", 10, &SafetyFilter::diffBCallback, this);

        // Initialize publisher
        pub_ = nh_.advertise<std_msgs::Bool>("/robot/object/ladybug/safe", 10);
    }

    void diffACallback(const std_msgs::Bool::ConstPtr& msg) {
        univ_A_state_ = msg->data;
    }

    void diffBCallback(const std_msgs::Bool::ConstPtr& msg) {
        univ_B_state_ = msg->data;
    }

    void evaluateAndPublish() {
        std_msgs::Bool output;
        output.data = univ_A_state_ && univ_B_state_;
        pub_.publish(output);
    }

private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_univ_A_;
    ros::Subscriber sub_univ_B_;
    ros::Publisher pub_;
    
    bool univ_A_state_ = true;
    bool univ_B_state_ = true;
};


int main(int argc, char **argv) {
    ros::init(argc, argv, "ladybug_safety_filter");
    SafetyFilter filter;

    ros::Rate rate(6); 
    while (ros::ok()) {
        ros::spinOnce();
        filter.evaluateAndPublish(); 
        rate.sleep(); 
    }

    return 0;
}