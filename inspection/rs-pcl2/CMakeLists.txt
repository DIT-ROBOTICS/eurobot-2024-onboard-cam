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

add_library(d-dbscan-cluster src/diff/dbscan-cluster.cpp)
target_link_libraries(d-dbscan-cluster ${catkin_LIBRARIES} ${PCL_LIBRARIES})
add_dependencies(d-dbscan-cluster ${catkin_EXPORTED_TARGETS})

add_library(d-voxelgrid-cube src/diff/voxelgrid-cube.cpp)
target_link_libraries(d-voxelgrid-cube ${catkin_LIBRARIES} ${PCL_LIBRARIES})
add_dependencies(d-voxelgrid-cube ${catkin_EXPORTED_TARGETS})

add_executable(d-main src/diff/d-main.cpp)
target_link_libraries(d-main d-voxelgrid-cube d-dbscan-cluster)
add_dependencies(d-main ${catkin_EXPORTED_TARGETS})

add_executable(entrypoint src/main/entrypoint.cpp)
target_link_libraries(entrypoint ${catkin_LIBRARIES})

#############
## Install ##
#############
