cmake_minimum_required(VERSION 3.16)

# set the project name and version
project(Spring22)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(Spring22)
add_subdirectory(Game)
add_subdirectory(glfw)