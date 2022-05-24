#include "../headers/Box.hpp"


void Box::MoveBack() {
    coordinates->x -= 1;
}

void Box::MoveForward() {
    coordinates->x += 1;
}

void Box::MoveLeft() {
    coordinates->y += 1;
}

void Box::MoveRight() {
    coordinates->y -= 1;
}

void Box::MoveUp() {
    coordinates->z += 1;
}

void Box::MoveDown() {
    coordinates->z -= 1;
}
