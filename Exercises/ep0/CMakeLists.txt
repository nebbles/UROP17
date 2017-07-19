SET(CUDA_USE_STATIC_CUDA_RUNTIME OFF)

cmake_minimum_required (VERSION 2.8)

project(hello1)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ep0 ep0.cpp)

target_link_libraries(ep0 ${OpenCV_LIBS})
