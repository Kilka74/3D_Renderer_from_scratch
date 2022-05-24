#include "../headers/Settings.hpp"
#include "cmath"

void Settings::HideMouse() {
    mouseHidden = true;
}

void Settings::ShowMouse() {
    mouseHidden = false;
}

void Settings::RotateLeft() {
    window_step_x -= window_step;
}

void Settings::RotateRight() {
    window_step_x += window_step;
}

void Settings::RotateUp() {
    window_step_y -= window_step;
}

void Settings::RotateDown() {
    window_step_y += window_step;
}

void Settings::ShiftUp() {
    pos.z -= speed;
}

void Settings::ShiftDown() {
    pos.z += speed;
}

void Settings::ObserverCloser() {
    offset.x -= offset_step;
}

void Settings::ObserverAway() {
    offset.x += offset_step;
}

void Settings::Distorsion1() {
    offset.y += offset_step;
}

void Settings::Distorsion2() {
    offset.y -= offset_step;
}

void Settings::Distorsion3() {
    offset.z += offset_step;
}

void Settings::Distorsion4() {
    offset.z -= offset_step;
}

void Settings::Slash() {
    offset = {1.0, 1.0, 1.0};
}

bool Settings::IsMouseHidden() {
    return mouseHidden;     
}

void Settings::PrepareShader(sf::Shader& shader) {
    shader.setUniform("u_offset", offset);
    shader.setUniform("u_pos", pos);
}

sf::VideoMode Settings::CreateVideoMode() const {
    return sf::VideoMode(window_w, window_h);
}

void Settings::CreateTexture(sf::RenderTexture& texture) const {
    texture.create(window_w, window_h);
}

void Settings::PrepareShader2(sf::Shader& shader) const {
    shader.setUniform("u_resolution", sf::Vector2f(static_cast<float>(window_w), static_cast<float>(window_h)));
    shader.setUniform("u_light", lightPos);
    shader.setUniform("u_samples", samples);
    shader.setUniform("u_refs", max_ref);
    shader.setUniform("u_max_dist", max_dist);
}

void Settings::MoveForward() {
    dir += {1.0, 0.0, 0.0};
}
void Settings::MoveLeft() {
    dir += {0.0, -1.0, 0.0};
}
void Settings::MoveBack() {
    dir += {-1.0, 0.0, 0.0};
}
void Settings::MoveRight() {
    dir += {0.0, 1.0, 0.0};
}

sf::Vector2f Settings::UpdatePicture() {
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
    return sf::Vector2f(mx, my);
}
