#pragma once
#include "Camera.hpp"
#include "Window.hpp"
#include "Figure.hpp"


class KeyboardHandler {
    Window &_window;
    Camera &_camera;
    std::vector<Figure*> &figures;
    size_t cur_fig;

public:
    explicit KeyboardHandler(Window &window, Camera &camera, std::vector<Figure*>& fgs) :
            _window(window), _camera(camera), figures(fgs) {cur_fig = 0;}
    void handle(const sf::Keyboard::Key &code);
    void PrevFigure();
    void NextFigure();
};
