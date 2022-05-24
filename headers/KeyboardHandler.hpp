#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.hpp"


class KeyboardHandler {
    sf::RenderWindow& _window;
    Settings& _current_settings;

public:
    KeyboardHandler(sf::RenderWindow& window,
                    Settings& current_settings);

    void handle(const sf::Keyboard::Key& code);
};
