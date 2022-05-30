#include "../headers/Triangle.hpp"


void Triangle::MoveBack() {
   auto tmp = coordinates->array;
   tmp[0] -= 1;
   tmp[3] -= 1;
   tmp[6] -= 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveForward() {
   auto tmp = coordinates->array;
   tmp[0] += 1;
   tmp[3] += 1;
   tmp[6] += 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveLeft() {
   auto tmp = coordinates->array;
   tmp[1] += 1;
   tmp[4] += 1;
   tmp[7] += 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveRight() {
   auto tmp = coordinates->array;
   tmp[1] -= 1;
   tmp[4] -= 1;
   tmp[7] -= 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveDown() {
   auto tmp = coordinates->array;
   tmp[2] -= 1;
   tmp[5] -= 1;
   tmp[8] -= 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}

void Triangle::MoveUp() {
   auto tmp = coordinates->array;
   tmp[2] += 1;
   tmp[5] += 1;
   tmp[8] += 1;
   *coordinates = sf::Glsl::Mat3(tmp);
}
