#include "../headers/Sphere.hpp"


void Sphere::MoveBack() {
    coordinates->x -= 1;
}

void Sphere::MoveForward() {
    coordinates->x += 1;
}

void Sphere::MoveLeft() {
    coordinates->y += 1;
}

void Sphere::MoveRight() {
    coordinates->y -= 1;
}

void Sphere::MoveUp() {
    coordinates->z += 1;
}

void Sphere::MoveDown() {
    coordinates->z -= 1;
}
