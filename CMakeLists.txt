cmake_minimum_required(VERSION 3.24)
project(chupa)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5
        COMPONENTS system window graphics audio REQUIRED)

add_executable(chupa
        main.cpp gameclasses/player.cpp gameclasses/player.h gameclasses/environment_obj.cpp gameclasses/environment_obj.h)
target_link_libraries(chupa sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
install(TARGETS chupa DESTINATION bin)