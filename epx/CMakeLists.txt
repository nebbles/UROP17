set(CUDA_USE_STATIC_CUDA_RUNTIME OFF)

cmake_minimum_required (VERSION 2.8)

project(TestTime1)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(testtt epx.cpp)

target_link_libraries(testtt ${OpenCV_LIBS})
