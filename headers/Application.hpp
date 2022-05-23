#pragma once

#include <cmath>
#include <random>
#include <string>
#include <utility>
#include "Window.hpp"

class Application {
    friend struct Window;

    Settings settings;
    World world;
    Window window;

public:
    explicit Application(const std::string &settings_file = "input",
                         const std::string &objects_file = "objects",
                         const std::string &shader_file = "Shader.frag");

    void run();
};