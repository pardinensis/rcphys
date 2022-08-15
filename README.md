# RCPhys

Proof of concept for a force-vector-design tool for rollercoaster track layouts.

## Build

```
mkdir build
cd build
cmake ..
make
```

## Usage

In `source/main.cpp`, fill the two vectors `verticalAccels` and `rotationalAccels` with the desired acceleration forces in m/s^2. Compile and run the program. It will generate a 3D mesh called track.obj inside the current working directory. You can open it with any 3D model viewer supporting the OBJ file format (such as meshlab).
