cmake_minimum_required(VERSION 3.16)
project(another-discord-bot
        VERSION 0.1.0
        DESCRIPTION "Just another discord bot by aubrey, this won't be for any sort of final release"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/dpp)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/config/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/config/)

find_package(toml11 CONFIG REQUIRED)

add_executable(another-discord-bot
        src/main.cpp
        src/main.hpp)

target_link_libraries(another-discord-bot
        dpp
        toml11::toml11)

target_include_directories(another-discord-bot PRIVATE libs/dpp/include)