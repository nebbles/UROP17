
set(CUDA_USE_STATIC_CUDA_RUNTIME OFF)
cmake_minimum_required (VERSION 2.8)

project(fdsa)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(asdf epx2.cpp)

target_link_libraries(asdf ${OpenCV_LIBS})
