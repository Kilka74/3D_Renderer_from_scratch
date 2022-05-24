#include "../headers/Triangle.hpp"


void Triangle::MoveBack() {
    //coordinates->x -= 1;
   auto tmp = coordinates->array;
   tmp[0] -= 1;
   tmp[3] -= 1;
   tmp[6] -= 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveForward() {
   // coordinates->x += 1;
   auto tmp = coordinates->array;
   tmp[0] += 1;
   tmp[3] += 1;
   tmp[6] += 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveLeft() {
    //coordinates->y += 1;
   auto tmp = coordinates->array;
   tmp[1] += 1;
   tmp[4] += 1;
   tmp[7] += 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveRight() {
   // coordinates->y -= 1;
   auto tmp = coordinates->array;
   tmp[1] -= 1;
   tmp[4] -= 1;
   tmp[7] -= 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveUp() {
   // coordinates->z += 1;
   auto tmp = coordinates->array;
   tmp[2] -= 1;
   tmp[5] -= 1;
   tmp[8] -= 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveDown() {
   // coordinates->z -= 1;
   auto tmp = coordinates->array;
   tmp[2] += 1;
   tmp[5] += 1;
   tmp[8] += 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}
