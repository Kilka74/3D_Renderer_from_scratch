#include "../headers/Application.hpp"
#include "../headers/Figure.hpp"

void Application::run() {
    auto figures = world.Figures();
    size_t cur_fig = 0;
    while (window.IsOpen()) {
        sf::Event event{};
        camera.ResetDir();
        while (window.PollEvent(event)) {
            window.ReloadWorld(world);
            window.StartChanges();
            KeyboardHandler handler(window, camera, figures, &cur_fig);
            if (event.type == sf::Event::Closed) {
                window.Close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                window.setMouseCursorVisible(false);
            } else if (event.type == sf::Event::KeyPressed) {
                handler.handle(event.key.code);
            }
        }
        if (window.NeedRedraw()) {
            window.Redraw(camera.UpdatePicture(), camera);
        }
        window.FinishChanges();
    }
    for (auto& f : figures) {
        delete f;
    }
}
