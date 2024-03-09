#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <vector>

class SafetyFilter {
public:
    SafetyFilter() : nh_("~"), diff_A_state_(false), diff_B_state_(false) {
        // Initialize subscribers
        sub_diff_A_ = nh_.subscribe("/diff_A/ladybug/safe", 10, &SafetyFilter::diffACallback, this);
        sub_diff_B_ = nh_.subscribe("/diff_B/ladybug/safe", 10, &SafetyFilter::diffBCallback, this);

        // Initialize publisher
        pub_ = nh_.advertise<std_msgs::Bool>("/robot/object/ladybug/safe", 10);
    }

    void diffACallback(const std_msgs::Bool::ConstPtr& msg) {
        diff_A_state_ = msg->data;
        evaluateAndPublish();
    }

    void diffBCallback(const std_msgs::Bool::ConstPtr& msg) {
        diff_B_state_ = msg->data;
        evaluateAndPublish();
    }

private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_diff_A_;
    ros::Subscriber sub_diff_B_;
    ros::Publisher pub_;

    bool diff_A_state_;
    bool diff_B_state_;

    void evaluateAndPublish() {
        std_msgs::Bool output;
        output.data = diff_A_state_ && diff_B_state_;;
        pub_.publish(output);
    }
};


int main(int argc, char **argv) {
    ros::init(argc, argv, "ladybug_safety_filter");
    SafetyFilter filter;
    ros::spin();
    return 0;
}