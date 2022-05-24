#include "../headers/Window.hpp"


Window::Window(const Settings &settings, const World &world, const std::string &shader_name) :
        _window(settings.CreateVideoMode(),
                "Ray tracing",
                sf::Style::Titlebar | sf::Style::Close),
        _shader(), _emptyTexture() {
    _window.setFramerateLimit(40);
    _window.setMouseCursorVisible(false);
    settings.CreateTexture(_emptyTexture);
    _emptySprite = sf::Sprite(_emptyTexture.getTexture());
    _shader.loadFromFile(shader_name, sf::Shader::Fragment);
    settings.LoadToShader(_shader);
    world.LoadToShader(_shader);
    std::random_device RandomGenerator;
    _e2 = std::mt19937(RandomGenerator());
    _dist = std::uniform_real_distribution<>(0.0f, 1.0f);
    _change = true;
}

void Window::Redraw(const sf::Vector2f& vec, Settings& settings) {
    settings.PrepareShader(_shader);
    _shader.setUniform("u_angle", vec);
    _shader.setUniform("u_seed1",
                               sf::Vector2f((float) _dist(_e2), (float) _dist(_e2)) *
                               999.0f);
    _shader.setUniform("u_seed2",
                               sf::Vector2f((float) _dist(_e2), (float) _dist(_e2)) *
                               999.0f);
    _window.draw(_emptySprite, &_shader);
    _window.display();
}

void Window::setMouseCursorVisible(bool flag) {
    _window.setMouseCursorVisible(flag);
}

void Window::StartChanges() {
     _change = true;
}

void Window::FinishChanges() {
    _change = false;
}

bool Window::IsChanges() const {
    return _change;
}

bool Window::IsOpen() {
    return _window.isOpen();
}

bool Window::PollEvent(sf::Event& event) {
    return _window.pollEvent(event);
}

void Window::Close() {
    _window.close();
}
