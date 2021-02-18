#!/bin/bash
xhost +local:root
export SRC_DIR=$(pwd)
# add --privileged to access gpu?
# see https://github.com/Intel-Media-SDK/MediaSDK/wiki/Running-on-GPU-under-docker
docker run -it -d --net=host -e DISPLAY --device /dev/dri:/dev/dri -v "/tmp/.X11-unix:/tmp/.X11-unix:rw" -v "$SRC_DIR:/home/devuser/source:rw" --name devbase-container devbase-image
# docker exec -it devbase-container /bin/bash
