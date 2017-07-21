cmake_minimum_required (VERSION 2.8)

project(ThreshinDetectinshield)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(epxthreshdetect epxthreshdetect.cpp)

target_link_libraries(epxthreshdetect ${OpenCV_LIBS})
