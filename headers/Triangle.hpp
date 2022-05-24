#pragma once
#include "Figure.hpp"
#include <SFML/Graphics.hpp>


class Triangle : public Figure {
    //sf::Glsl::Mat3* coordinates;

public:
    explicit Triangle(sf::Glsl::Mat3* c) {}
    void MoveForward();
    void MoveBack();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
};
