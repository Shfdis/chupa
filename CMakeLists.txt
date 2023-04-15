cmake_minimum_required(VERSION 3.24)
project(chupa)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_executable(chupa
        main.cpp gameclasses/player.cpp gameclasses/player.h gameclasses/game.cpp
        gameclasses/game.h gameclasses/game_obj.h gameclasses/game_obj.cpp
        gameclasses/fireball.cpp gameclasses/fireball.h
        gameclasses/target.h gameclasses/target.cpp)
target_link_libraries(chupa sfml-graphics)
