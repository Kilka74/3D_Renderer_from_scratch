#pragma once

#include "Settings.hpp"
#include "Window.hpp"


class KeyboardHandler {
    Window &_window;
    Settings &_current_settings;

public:
    explicit KeyboardHandler(Window &window, Settings &current_settings) :
            _window(window), _current_settings(current_settings) {};

    void handle(const sf::Keyboard::Key &code);
};
