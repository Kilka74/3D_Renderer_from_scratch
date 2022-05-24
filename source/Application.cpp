#include "../headers/Application.hpp"

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
            } else if (event.type == sf::Event::KeyPressed) {
                handler.handle(event.key.code);
            }
        }
        if (window.NeedRedraw()) {
            window.Redraw(settings.UpdatePicture(), settings);
        }
        window.FinishChanges();
    }
}
