---
description: Step by step instructions on building with cmake
---

# Building with CMake

## Setup for your platform

For Linux you will need to install a few libraries, on Windows these are distributed with the engine.

On Debian install these:

```text
sudo apt install libsdl2-dev libsdl2-2.0-0 libvulkan-1 libvulkan-dev vulkan-validationlayers-dev
```

## Generating and building

To build you can run this:

```text
mkdir build && cd build
cmake ../ -DPLATFORM="x86" -DUSE_AVX=ON -DUSE_SSE41=ON -DINSTALL_DIR="~/games/wavelength/"
make -j16 # this runs make with 16 threads, you can reduce this if you have less ram than me (i have 32gb)
```

Do `cmake ../ -h` for more info on options

