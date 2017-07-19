cmake_minimum_required (VERSION 2.8)

project(IWonderIfThisIsTheWindowName)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(epx3 epx3.cpp)

target_link_libraries(epx3 ${OpenCV_LIBS})
