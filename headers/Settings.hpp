#pragma once
#include <SFML/Graphics.hpp>
#include <string>


struct Settings {
public:
    int window_w, window_h, window_step, samples, max_ref, window_step_x, window_step_y;
    bool mouseHidden;
    float speed, offset_step, max_dist;
    sf::Vector3f pos, offset;
    sf::Vector2f lightPos;
    Settings() = default;
    Settings(const std::string& file);
};
