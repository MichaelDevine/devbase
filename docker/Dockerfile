# Devine's Base Dockerfile

FROM ubuntu:20.04

# Enable passing UID from host
ARG UNAME=devuser
ARG UID=1000
ARG GID=1000

# Suppress the tzdata prompt
ARG DEBIAN_FRONTEND=noninteractive

# Build and other Basics
RUN apt-get update && apt-get install -y \
  apt-transport-https \
  build-essential \
  cmake \
  git \
  openssl \
  sudo \
  wget \
  xauth \
  nano \
  iproute2 \
  && rm -rf /var/lib/apt/lists/*
  
# For X11
RUN apt-get update && apt-get install -y \
  libx11-xcb-dev \
  libxcb-dri3-0 \
  libdrm2 \
  libgbm1 \
  libasound2 \
  libcanberra-gtk-module \
  libcanberra-gtk3-module \
  && rm -rf /var/lib/apt/lists/*

# Install the Microsoft repository for code
RUN wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
RUN install -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/
RUN sh -c 'echo "deb [arch=amd64 signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/vscode stable main" > /etc/apt/sources.list.d/vscode.list'

# See next section, commented out, for retreiving current vscode. Here we pull an older version 
# because the current version cannot run in a docker container.
RUN apt-get update \
    && wget -O code.deb https://update.code.visualstudio.com/1.47.3/linux-deb-x64/stable \
    && apt install -y ./code.deb \
    && rm code.deb \
    && rm -rf /var/lib/apt/lists/*

# Current code does not work inside docker
# RUN apt-get update && apt-get install -y \
#  code \
#  && rm -rf /var/lib/apt/lists/*

# Now, add the non-root user and switch to it
RUN addgroup --gid $GID $UNAME
RUN adduser --gid $GID --uid $UID --disabled-password --gecos '' $UNAME \
  && echo "devuser ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/devuser \
  && chmod 0440 /etc/sudoers.d/devuser
USER devuser
WORKDIR /home/devuser

