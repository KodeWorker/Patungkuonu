# Patungkuonu Project
---

## Contents
1. [Description](#description)
2. [Build Instructions](#build-instructions)
3. [Project Structure](#project-structure)
4. [DOTO List](#todo-list)
5. [License](./license)
6. [Devlog](./doc/devlog.md)

## Description
This is my persional project aimed at building a custom 2D game engine.
Patungkuonu is the name of the highest mountain in my home country.

## Build Instructions
### Windows
```powershell
mkdir build
cd build
cmake -G"Visual Studio 17" -A"x64" ..
cmake --build . --config release
```
### Linux
1. Install dependencies
```console
sudo apt-get install build-essential git make \
pkg-config cmake ninja-build gnome-desktop-testing libasound2-dev libpulse-dev \
libaudio-dev libjack-dev libsndio-dev libx11-dev libxext-dev \
libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev \
libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev \
libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev fcitx-libs-dev
```
2. Install Cpplint
```console
pip install cpplint # or sudo apt-get install cpplint
```
3. Build engine
```console
mkdir build
cd build
cmake ..
cmake --build . --config release
```

## Project Structure

## TODO List
- [x] SDL
- [x] cpplint
- [x] googletest
- [x] settings
- [x] sprite object
  - [x] basic operation
  - [x] subsqence of a sprite
- [ ] player object

