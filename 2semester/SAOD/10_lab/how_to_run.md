# Required packages

cmake, ninja(recommended), clang 18/gcc 14(if lower use std::cout), clang-format

# Run

```
mkdir build
cd build
cmake .. -G=Ninja
ninja -j$(nproc)
./10_lab
```

# Clang-format

```
clang-format -i *.cpp
```
