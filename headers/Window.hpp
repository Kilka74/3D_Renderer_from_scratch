#pragma once
#include "Application.hpp"


struct Window {
    sf::Window _window;
    sf::Shader _shader;
    bool _change;
    std::uniform_real_distribution<> _dist;
    sf::Sprite _emptySprite;
    std::mt19937 _e2;

public:
    Window(Application& app);
};
