cmake_minimum_required(VERSION 3.22)
project(3D_Renderer_from_scratch)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
include_directories(source)

add_executable(3D_Renderer_from_scratch
        headers/Application.hpp
        headers/FileReader.hpp
        headers/KeyboardHandler.hpp
        headers/Settings.hpp
        headers/Window.hpp
        headers/World.hpp
        source/Application.cpp
        source/FileReader.cpp
        source/KeyboardHandler.cpp
        source/Settings.cpp
        source/Window.cpp
        source/World.cpp
        Main.cpp)
