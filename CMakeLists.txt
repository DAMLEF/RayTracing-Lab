cmake_minimum_required(VERSION 3.28)
project(RayTracing_Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(RayTracing_Lab
        src/main.cpp
        src/vec3.h
        src/color.h
        src/ray.h
        src/hittable.h
        src/sphere.h)
