#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <vector>

class SafetyFilter {
public:
    SafetyFilter() : nh_("~"), window_size_(3), diff_A_state_(false), diff_B_state_(false) {
        // Initialize subscribers
        sub_diff_A_ = nh_.subscribe("/diff_A/ladybug/safe", 10, &SafetyFilter::diffACallback, this);
        sub_diff_B_ = nh_.subscribe("/diff_B/ladybug/safe", 10, &SafetyFilter::diffBCallback, this);

        // Initialize publisher
        pub_ = nh_.advertise<std_msgs::Bool>("/robot/object/ladybug/safe", 10);

        // Initialize the window filter with False
        window_filter_ = std::vector<bool>(window_size_, false);
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
    int window_size_;
    std::vector<bool> window_filter_;
    bool diff_A_state_;
    bool diff_B_state_;

    void evaluateAndPublish() {
        // Update window filter
        bool current_state = diff_A_state_ && diff_B_state_;
        window_filter_.push_back(current_state);
        window_filter_.erase(window_filter_.begin());

        // Check window filter
        bool publish_state = true;
        for (bool state : window_filter_) {
            if (!state) {
                publish_state = false;
                break;
            }
        }

        // Publish result
        std_msgs::Bool output;
        output.data = publish_state;
        pub_.publish(output);
    }
};


int main(int argc, char **argv) {
    ros::init(argc, argv, "ladybug_safety_filter");
    SafetyFilter filter;
    ros::spin();
    return 0;
}