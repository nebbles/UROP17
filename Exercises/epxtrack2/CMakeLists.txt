cmake_minimum_required (VERSION 2.8)

project(epxtrack2.0)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(HSV2 epxtrack2.cpp)

target_link_libraries(HSV2 ${OpenCV_LIBS})
