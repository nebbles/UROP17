cmake_minimum_required (VERSION 2.8)

project(MazeyWilliams)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(epxmaze epxmaze.cpp)

target_link_libraries(epxmaze ${OpenCV_LIBS})
