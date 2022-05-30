#pragma once
#include "Figure.hpp"
#include <SFML/Graphics.hpp>


class Box : public Figure {
    sf::Glsl::Vec3* coordinates;

public:
    explicit Box(sf::Glsl::Vec3* c) : coordinates(c) {}
    void MoveForward();
    void MoveBack();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
};
