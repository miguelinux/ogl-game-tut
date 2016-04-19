#!/bin/bash -e
# based on https://github.com/IntelRealSense/librealsense/blob/master/scripts/install_glfw3.sh
# Installs glfw3 from source as a shared lib

# Make sure glfw (or any previous version) is not already installed
sudo apt-get update

sudo apt-get install build-essential cmake git xorg-dev libglu1-mesa-dev

#https://github.com/glfw/glfw/archive/3.1.2.tar.gz
curl -O https://github.com/glfw/glfw/releases/download/3.1.2/glfw-3.1.2.tar.gz

tar xzf glfw-3.1.2.tar.gz

pushd glfw-3.1.2

cmake . -DBUILD_SHARED_LIBS=ON

make

sudo make install

sudo ldconfig

popd

echo "Done installing glfw3!"
