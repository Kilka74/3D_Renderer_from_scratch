#pragma once
#include <random>
#include "FileReader.hpp"


struct Window {
    sf::RenderWindow _window;
    sf::Shader _shader;
    bool _change;
    std::uniform_real_distribution<> _dist;
    sf::RenderTexture _emptyTexture;
    sf::Sprite _emptySprite;
    std::mt19937 _e2;

public:
    Window(const Settings &settings, const World &world, const std::string &shader_name);
};
