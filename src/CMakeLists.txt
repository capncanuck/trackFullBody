cmake_minimum_required(VERSION 2.8)
project(trackFullBody)
find_package(OpenCV REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
ADD_DEFINITIONS(
    --std=c++11
    -g3 -O0
    -Wall
)
