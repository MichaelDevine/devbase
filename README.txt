# System Setup Steps

# Remove any old Docker on system 
sudo apt-get remove docker docker-engine docker.io containerd runc
sudo apt autoremove

# Install items required to interact with Docker repository
sudo apt-get update
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common
    
# Add Docker GPG key to local system
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

# Add the stable Docker repository to apt
sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"

# Now, install Docker
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io

# Add group and associate user with group
 sudo groupadd docker
 sudo usermod -aG docker $USER
# Log out, and log back in

# Verify install
sudo docker run hello-world

# Enable docker to run on boot
sudo systemctl enable docker

# Build the docker image
docker build -t devbase-image ./docker

# Now, run the docker image. The user subdirectory "source" will be linked to 
# the host user's subdirectory for this repo
export SRC_DIR=$(pwd)
docker run -it -d --net=host -e DISPLAY -v "/tmp/.X11-unix:/tmp/.X11-unix:rw" -v $SRC_DIR:/home/devuser/source --name devbase-container devbase-image

# Shell into the container
docker start devbase-container 
docker exec -it devbase-container /bin/bash

######
## Code depends on googltest -- should this be pulled inside the container, or outside? 
git clone https://github.com/google/googletest.git

##################################################################
## To Remove the Container

docker container stop devbase-container
docker rm devbase-container


