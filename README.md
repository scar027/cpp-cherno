# Basic C++ with CMake
C++ code based on the amazing [playlist](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb) by The Cherno structured with CMake.

## CMake 
Check if CMake is installed in your system by running 
```bash
cmake --version
```
in the Terminal. Install it if it is not installed. This build currently requires a minimum CMake version of 3.22 but you can try changing that in the root CMakeLists.txt file and verify if your code compiles if you face any issues because of that.

Header files for functions have been stored in sample-library in the include directory and their definitions are stored in the src directory.  The main file lies in the examples directory.

The CMakeLists.txt of the src directory should be updated when new function definitions are created.


## Build Instructions

### VSCode

1. Install the CMake extension by twxs and the CMake Tools extension by Microsoft.
1. Open Command Palette and select CMake: Scan for kits. CMake should automatically configure your project now and once its done you can simply click the triangular play button at the bottom of the IDE to run your code.

### Terminal
Open a new Terminal in the root folder of the project and do the following:
1. Create a new directory called 'build' to store your build files and change your directory from the root directory to the build directory.
```bash
mkdir build && cd build
```
2. Use CMake and Make to build your project from the build directory
```bash
cmake ..
```
```bash
make
```
3. Run the main executable from the build directory
```bash
./examples/main
```