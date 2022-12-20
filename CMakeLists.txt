cmake_minimum_required(VERSION 3.10)
project(FlipToOnes)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add the setRowColToOne.cpp file
add_executable(flipToOnes src/flipToOnes.cpp)

# Add the setRowColToOne_test.cpp file
add_executable(flipToOnes_test test/flipToOnes_test.cpp)# src/setRowColToOne.cpp)

# Link the Google Test library
target_link_libraries(flipToOnes_test gtest)
