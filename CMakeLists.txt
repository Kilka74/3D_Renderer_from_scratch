cmake_minimum_required(VERSION 3.22)
project(3D_Renderer_from_scratch)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
include_directories(source)

add_executable(3D_Renderer_from_scratch
        headers
        source
        Main.cpp
        Shader.frag)
