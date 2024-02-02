cmake_minimum_required(VERSION 3.0.2)
project(rs-pcl2)

find_package(catkin REQUIRED COMPONENTS
  pcl_ros REQUIRED
  roscpp
  sensor_msgs
)

################################################
## Declare ROS messages, services and actions ##
################################################

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

###################################
## catkin specific configuration ##
###################################

catkin_package(
  # INCLUDE_DIRS include
  # LIBRARIES your_package_name
  CATKIN_DEPENDS pcl_ros roscpp sensor_msgs
  # DEPENDS pcl_ros
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

add_definitions(${PCL_DEFINITIONS})

add_executable(differential src/differential.cpp)
target_link_libraries(differential ${catkin_LIBRARIES} ${PCL_LIBRARIES})

#############
## Install ##
#############
