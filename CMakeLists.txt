cmake_minimum_required(VERSION 3.29)
project(conversion_a1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(conversion_a1
        .idea/.gitignore
        .idea/conversion-a1.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        main.cpp
        main.h
        testing.h
        testing.cpp)
