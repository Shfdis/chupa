cmake_minimum_required(VERSION 3.24)
project(chupa)

set(CMAKE_CXX_STANDARD 14)

<<<<<<< HEAD
find_package(SFML 2.5
        COMPONENTS system window graphics audio REQUIRED)

add_executable(chupa
        main.cpp gameclasses/player.cpp gameclasses/player.h gameclasses/environment_obj.cpp gameclasses/environment_obj.h)
target_link_libraries(chupa sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
install(TARGETS chupa DESTINATION bin)
=======
add_executable(chupa
        main.cpp player.cpp player.h environment_obj.cpp environment_obj.h)
>>>>>>> parent of 527ab20 (Cmake config)
