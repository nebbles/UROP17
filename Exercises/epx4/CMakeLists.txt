cmake_minimum_required (VERSION 2.8)

project(WindowName)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(epx4 epx4.cpp)

target_link_libraries(epx4 ${OpenCV_LIBS})
