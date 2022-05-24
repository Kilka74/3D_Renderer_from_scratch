#include "../headers/Camera.hpp"
#include "../headers/FileReader.hpp"
#include "cmath"

void Camera::RotateLeft() {
    window_step_x -= window_step;
}

void Camera::RotateRight() {
    window_step_x += window_step;
}

void Camera::RotateUp() {
    window_step_y -= window_step;
}

void Camera::RotateDown() {
    window_step_y += window_step;
}

void Camera::ShiftUp() {
    pos.z -= speed;
}

void Camera::ShiftDown() {
    pos.z += speed;
}

void Camera::ObserverCloser() {
    offset.x -= offset_step;
}

void Camera::ObserverAway() {
    offset.x += offset_step;
}

void Camera::ShrinkWidth() {
    offset.y += offset_step;
}

void Camera::StretchWidth() {
    offset.y -= offset_step;
}

void Camera::ShrinkHigh() {
    offset.z += offset_step;
}

void Camera::StretchHigh() {
    offset.z -= offset_step;
}

void Camera::ResetOffset() {
    offset = {1.0, 1.0, 1.0};
}

void Camera::PrepareShader(sf::Shader& shader) {
    shader.setUniform("u_offset", offset);
    shader.setUniform("u_pos", pos);
}

sf::VideoMode Camera::CreateVideoMode() const {
    return sf::VideoMode(window_w, window_h);
}

void Camera::CreateTexture(sf::RenderTexture& texture) const {
    texture.create(window_w, window_h);
}

void Camera::LoadToShader(sf::Shader& shader) const {
    shader.setUniform("u_resolution", sf::Vector2f(static_cast<float>(window_w), static_cast<float>(window_h)));
    shader.setUniform("u_light", lightPos);
    shader.setUniform("u_samples", samples);
    shader.setUniform("u_refs", max_ref);
    shader.setUniform("u_max_dist", max_dist);
}

void Camera::MoveForward() {
    dir += {1.0, 0.0, 0.0};
}
void Camera::MoveLeft() {
    dir += {0.0, -1.0, 0.0};
}
void Camera::MoveBack() {
    dir += {-1.0, 0.0, 0.0};
}
void Camera::MoveRight() {
    dir += {0.0, 1.0, 0.0};
}

sf::Vector2f Camera::UpdatePicture() {
    float mx = static_cast<float>(window_step_x) / static_cast<float>(window_w) - 0.5f;
    float my = static_cast<float>(window_step_y) / static_cast<float>(window_h) - 0.5f;
    sf::Vector3f dirTemp;
    dirTemp.z = dir.z * std::cos(-my) - dir.x * std::sin(-my);
    dirTemp.x = dir.z * std::sin(-my) + dir.x * std::cos(-my);
    dirTemp.y = dir.y;
    dir.x = dirTemp.x * std::cos(mx) - dirTemp.y * std::sin(mx);
    dir.y = dirTemp.x * std::sin(mx) + dirTemp.y * std::cos(mx);
    dir.z = dirTemp.z;
    pos += dir * speed;
    return {mx, my};
}

void Camera::ResetDir() {
    dir = sf::Vector3f(0.0f, 0.0f, 0.0f);
}

