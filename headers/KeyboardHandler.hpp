#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.hpp"


class KeyboardHandler {
    sf::RenderWindow& _window;
    Settings& _current_settings;
    sf::Vector3f& _dir;
    const Settings& _base_settings;

public:
    KeyboardHandler(sf::RenderWindow& window,
                    Settings& current_settings,
                    sf::Vector3f& dir, 
                    const Settings& base_settings);

    void handle(const sf::Keyboard::Key& code);
};
