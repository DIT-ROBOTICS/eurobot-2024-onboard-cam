#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <vector>

class SafetyFilter {
public:
    SafetyFilter() : nh_("~"), window_size_(3), univ_A_state_(false), univ_B_state_(false) {
        // Initialize subscribers
        sub_univ_A_ = nh_.subscribe("/univ_A/ladybug/safe", 10, &SafetyFilter::univACallback, this);
        sub_univ_B_ = nh_.subscribe("/univ_B/ladybug/safe", 10, &SafetyFilter::univBCallback, this);

        // Initialize publisher
        pub_ = nh_.advertise<std_msgs::Bool>("/robot/object/ladybug/safe", 10);

        // Initialize the window filter with False
        window_filter_ = std::vector<bool>(window_size_, false);
    }

    void univACallback(const std_msgs::Bool::ConstPtr& msg) {
        univ_A_state_ = msg->data;
        evaluateAndPublish();
    }

    void univBCallback(const std_msgs::Bool::ConstPtr& msg) {
        univ_B_state_ = msg->data;
        evaluateAndPublish();
    }

private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_univ_A_;
    ros::Subscriber sub_univ_B_;
    ros::Publisher pub_;
    int window_size_;
    std::vector<bool> window_filter_;
    bool univ_A_state_;
    bool univ_B_state_;

    void evaluateAndPublish() {
        // Update window filter
        bool current_state = univ_A_state_ && univ_B_state_;
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