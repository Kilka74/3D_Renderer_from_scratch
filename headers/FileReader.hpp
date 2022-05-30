#pragma once
#include "Camera.hpp"
#include "World.hpp"

class FileReader {
public:
    static CameraImage get_camera(const std::string &filename);
    static WorldImage get_world(const std::string &filename);
};
