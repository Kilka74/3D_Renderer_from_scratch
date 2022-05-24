#include "../headers/Application.hpp"
#include <iostream>

Application::Application(const std::string &settings_file, const std::string &objects_file,
                         const std::string &shader_file) :
        settings(FileReader::get_settings(settings_file)),
        world(FileReader::get_world(objects_file)),
        window(settings, world, shader_file) {}

void Application::run() {
    while (window.IsOpen()) {
        sf::Event event{};
        settings.ResetDir();
        while (window.PollEvent(event)) {
            window.StartChanges();
            KeyboardHandler handler(window, settings);
            if (event.type == sf::Event::Closed) {
                window.Close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                window.setMouseCursorVisible(false);
                settings.HideMouse();
            } else if (event.type == sf::Event::KeyPressed) {
                handler.handle(event.key.code);
            }
        }
        if (settings.IsMouseHidden() && window.IsChanges()) {
            window.Redraw(settings.UpdatePicture(), settings);
        }
        window.FinishChanges();
    }
}
