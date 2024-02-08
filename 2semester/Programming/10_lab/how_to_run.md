# Required packages
cmake, ninja(recommended), clang/gcc, clang-format

# Before run
```
mv 1.cpp main.cpp
````

# Run
```
mkdir build
cd build
cmake .. -G=Ninja
ninja -j$(nproc)
./10_lab
```
