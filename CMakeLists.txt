cmake_minimum_required(VERSION 3.24)
project(chupa)

set(CMAKE_CXX_STANDARD 14)

add_executable(chupa
        main.cpp player.cpp player.h environment_obj.cpp environment_obj.h)
