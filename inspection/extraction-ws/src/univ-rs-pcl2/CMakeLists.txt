cmake_minimum_required(VERSION 3.0.2)
project(univ-rs-pcl2)

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
#  INCLUDE_DIRS include
#  LIBRARIES univ-rs-pcl2
  CATKIN_DEPENDS pcl_ros roscpp sensor_msgs
#  DEPENDS system_lib
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

add_library(U-dbscan-cluster src/dbscan-cluster.cpp)
target_link_libraries(U-dbscan-cluster ${catkin_LIBRARIES} ${PCL_LIBRARIES})
add_dependencies(U-dbscan-cluster ${catkin_EXPORTED_TARGETS})

add_library(U-voxelgrid-cube src/voxelgrid-cube.cpp)
target_link_libraries(U-voxelgrid-cube ${catkin_LIBRARIES} ${PCL_LIBRARIES})
add_dependencies(U-voxelgrid-cube ${catkin_EXPORTED_TARGETS})

add_executable(U-main-a src/main-a.cpp)
target_link_libraries(U-main-a U-voxelgrid-cube U-dbscan-cluster)
add_dependencies(U-main-a ${catkin_EXPORTED_TARGETS})

add_executable(U-main-b src/main-b.cpp)
target_link_libraries(U-main-b U-voxelgrid-cube U-dbscan-cluster)
add_dependencies(U-main-b ${catkin_EXPORTED_TARGETS})

add_executable(U-entrypoint src/entrypoint.cpp)
target_link_libraries(U-entrypoint ${catkin_LIBRARIES})

add_executable(U-safety-ab src/safety-ab.cpp)
target_link_libraries(U-safety-ab ${catkin_LIBRARIES})
add_dependencies(U-safety-ab ${catkin_EXPORTED_TARGETS})

#############
## Install ##
#############