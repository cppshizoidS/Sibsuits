# Required packages
cmake, ninja(recommended), clang/gcc, clang-format

# Before run
```
mv 3.cpp main.cpp
````

# Run
```
mkdir build
cd build
cmake .. -G=Ninja
ninja -j$(nproc)
./1_task
```
