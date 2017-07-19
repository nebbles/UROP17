cmake_minimum_required (VERSION 2.8)

project(ThreshinHoldkinshield)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(epxthreshold epxthreshold.cpp)

target_link_libraries(epxthreshold ${OpenCV_LIBS})
