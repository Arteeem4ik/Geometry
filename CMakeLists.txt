cmake_minimum_required(VERSION 3.20)
project(GeometryClasses)

set(CMAKE_CXX_STANDARD 20)

add_executable(GeometryClasses src/point.cpp i_shape.h vector.h point.h segment.h polygon.h ray.h line.h circle.h src/segment.cpp src/ray.cpp src/circle.cpp src/polygon.cpp src/line.cpp main.cpp src/vector.cpp)
