cmake_minimum_required(VERSION 3.27)
project(DinoGame)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)
FetchContent_MakeAvailable(SFML)

add_executable(Dino
        main.cpp
        Dino.cpp
        Dino.h
        SoundManager.cpp
        SoundManager.h
        Globals.cpp
        Globals.h
)
target_link_libraries(Dino sfml-graphics sfml-audio)