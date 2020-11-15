#!/bin/bash

export SRC_DIR=$(pwd)
docker run -it -d --net=host -e DISPLAY -v "/tmp/.X11-unix:/tmp/.X11-unix:rw" -v $SRC_DIR:/home/devuser/source --name devbase-container devbase-image
docker exec -it devbase-container /bin/bash
