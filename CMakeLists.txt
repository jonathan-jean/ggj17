cmake_minimum_required(VERSION 3.6)
project(ggj17)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/PhysicsEngine.cpp src include)

add_executable(ggj17 ${SOURCE_FILES})