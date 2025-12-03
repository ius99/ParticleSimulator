cmake_minimum_required(VERSION 3.16)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/shivansh/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(untitled1)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

add_executable(untitled1 main.cpp
        particle.h
        constants.h
)
target_link_libraries(untitled1 PRIVATE raylib)