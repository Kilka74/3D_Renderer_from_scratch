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
    settings.PrepareShader2(_shader);
    world.LoadToShader(_shader);
    std::random_device RandomGenerator;
    _e2 = std::mt19937(RandomGenerator());
    _dist = std::uniform_real_distribution<>(0.0f, 1.0f);
    _change = true;
}
