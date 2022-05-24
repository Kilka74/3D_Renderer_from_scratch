#include "../headers/Application.hpp"
#include <iostream>

Application::Application(const std::string &settings_file, const std::string &objects_file,
                         const std::string &shader_file) :
        settings(FileReader::get_settings(settings_file)),
        world(FileReader::get_world(objects_file)),
        window(settings, world, shader_file) {}

void Application::run() {
    while (window._window.isOpen()) {
        sf::Event event{};
        settings.ResetDir();
        while (window._window.pollEvent(event)) {
            window._change = true;
            KeyboardHandler handler(window._window, settings);
            if (event.type == sf::Event::Closed) {
                window._window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                window._window.setMouseCursorVisible(false);
                settings.HideMouse();
            } else if (event.type == sf::Event::KeyPressed) {
                handler.handle(event.key.code);
            }
        }
        if (settings.IsMouseHidden() && window._change) {
            Redraw(settings.UpdatePicture());
        }
        window._change = false;
    }
}

void Application::Redraw(sf::Vector2f vec) {
    settings.PrepareShader(window._shader);
    window._shader.setUniform("u_angle", vec);
    window._shader.setUniform("u_seed1",
                               sf::Vector2f((float) window._dist(window._e2), (float) window._dist(window._e2)) *
                               999.0f);
    window._shader.setUniform("u_seed2",
                               sf::Vector2f((float) window._dist(window._e2), (float) window._dist(window._e2)) *
                               999.0f);
    window._window.draw(window._emptySprite, &window._shader);
    window._window.display();
}
