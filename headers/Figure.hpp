#pragma once
#include <SFML/Graphics.hpp>


class Figure {
public:
    virtual void MoveForward() = 0;
    virtual void MoveBack() = 0;
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
    virtual void MoveUp() = 0;
    virtual void MoveDown() = 0;
    virtual ~Figure() = default;
};
