cmake_minimum_required(VERSION 3.29)
project(virtualtb3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS
    System
    Window
    Graphics
)

add_executable(virtualtb3 src/main.cpp src/Robot.cpp)

target_link_libraries(virtualtb3 PRIVATE
    SFML::System
    SFML::Window
    SFML::Graphics
)
