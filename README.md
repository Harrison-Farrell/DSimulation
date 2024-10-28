# D-SIM

## Linux Build Dependencies

### SDL3

Ubuntu 18.04, all available features enabled:
```
sudo apt-get install build-essential git make \
pkg-config cmake ninja-build gnome-desktop-testing libasound2-dev libpulse-dev \
libaudio-dev libjack-dev libsndio-dev libx11-dev libxext-dev \
libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev \
libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev \
libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev fcitx-libs-dev
```
Ubuntu 22.04+ can also add ```libpipewire-0.3-dev libwayland-dev```  to that command line.

### Dear IMGUI
 Dear IMGUI requires both SL3 & OpenGL as dependencies
```
sudo apt-get install libglew-dev
```

## Building.

Once all the build dependencies have been installed. \
Run the following terminal commands.
```
git clone https://github.com/Harrison-Farrell/DSimulation.git \
cd DSimulation
mkdir build
cd build 
cmake ..
cmake --build .
```