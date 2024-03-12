FROM ros:noetic

LABEL org.opencontainers.image.authors="ohin"

ARG USERNAME=yolo
#change to your user id and group id
ARG USER_UID=1000 
ARG USER_GID=$USER_UID
ARG TZ=Asia/Taipei

ENV SHELL /bin/bash

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential \
    curl \
    git \
    sudo \
    lsof \
    cmake \
    python3-pip \
    v4l-utils \
    apt-transport-https \
    ros-noetic-tf* \
    ros-noetic-rviz \
    ros-noetic-diagnostic-updater \
    libgl1-mesa-glx libssl-dev libusb-1.0-0-dev libudev-dev pkg-config libgtk-3-dev \
    libqt5gui5 libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev at \
    && rm -rf /var/lib/apt/lists/*
RUN apt-get clean all

RUN pip3 install numpy \
    && pip3 install opencv-python \
    && pip3 install pyrealsense2

#install pytorch and ultralytics
RUN pip3 install --upgrade pip python-dateutil \
    && pip3 install pillow \
    && pip3 install torch torchvision \
    && pip3 install ultralytics

#Install Intel RealSense SDK 2.0(v2.50.0)
RUN git clone --branch v2.50.0 https://github.com/IntelRealSense/librealsense.git /opt/librealsense 
WORKDIR /opt/librealsense/build
RUN cmake ../ -DBUILD_EXAMPLES=true -DCMAKE_BUILD_TYPE=Release \
    && make -j4 && sudo make install

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME \
    && ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone 
# Set timezone

USER $USERNAME
#clone ros pkgs
WORKDIR /home/$USERNAME/realsense-ws/src
RUN git clone -b noetic-devel https://github.com/pal-robotics/aruco_ros.git && \
    git clone -b ros1-legacy --single-branch https://github.com/IntelRealSense/realsense-ros.git && \
    (cd realsense-ros && git checkout $(git tag | sort -V | grep -P "^2.\\d+\\.\\d+" | tail -1)) && \
    sudo apt update && \
    rosdep update && \
    rosdep install --from-paths . --ignore-src -r -y && \
    cd .. && \
    /bin/bash -c 'source /opt/ros/$ROS_DISTRO/setup.bash; catkin_make' && \
    echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc \
    && sudo rm -rf /var/lib/apt/lists/* 

#clone into workspace
WORKDIR /home/$USERNAME/yolo
RUN git clone https://github.com/HungPinChiu/yolo

# fix tf2_server_test_nodelets.xml missing error
# COPY fixing.sh /fixing.sh
# RUN /bin/bash /fixing.sh

SHELL ["/bin/bash","-ic"]
