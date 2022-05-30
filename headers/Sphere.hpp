#pragma once
#include "Figure.hpp"
#include <SFML/Graphics.hpp>


class Sphere : public Figure {
    sf::Glsl::Vec4* coordinates;

public:
    explicit Sphere(sf::Glsl::Vec4* c) : coordinates(c) {}
    void MoveForward();
    void MoveBack();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
};
