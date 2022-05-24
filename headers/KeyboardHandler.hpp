#pragma once
#include "Camera.hpp"
#include "Window.hpp"


class KeyboardHandler {
    Window &_window;
    Camera &_camera;

public:
    explicit KeyboardHandler(Window &window, Camera &camera) :
            _window(window), _camera(camera) {};

    void handle(const sf::Keyboard::Key &code);
};
