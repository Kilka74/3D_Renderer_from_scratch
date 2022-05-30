#pragma once
#include <string>
#include "KeyboardHandler.hpp"
#include "Window.hpp"


class Application {
    friend class Window;

    Camera camera;
    World world;
    Window window;

public:
    explicit Application(const std::string &settings_file = "data/input",
                         const std::string &objects_file = "data/objects",
                         const std::string &shader_file = "data/Shader.frag") :
            camera(FileReader::get_camera(settings_file)),
            world(FileReader::get_world(objects_file)),
            window(camera, world, shader_file) {};

    void run();
};
