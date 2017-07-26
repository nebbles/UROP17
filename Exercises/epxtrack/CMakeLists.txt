cmake_minimum_required (VERSION 2.8)

project(Tracktor)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(epxtrack epxtrack.cpp)

target_link_libraries(epxtrack ${OpenCV_LIBS})
