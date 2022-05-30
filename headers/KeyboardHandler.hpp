#pragma once
#include "Camera.hpp"
#include "Window.hpp"
#include "Figure.hpp"
#include <memory>


class KeyboardHandler {
    Window &_window;
    Camera &_camera;
    std::vector<std::shared_ptr<Figure>> &figures;
    size_t* cur_fig;

public:
    explicit KeyboardHandler(Window &window, Camera &camera, std::vector<std::shared_ptr<Figure>>& fgs, size_t* cf) :
            _window(window), _camera(camera), figures(fgs), cur_fig(cf) {}
    void handle(const sf::Keyboard::Key &code);
    void PrevFigure();
    void NextFigure();
};
