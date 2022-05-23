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
        sf::Vector3f dir = sf::Vector3f(0.0f, 0.0f, 0.0f);
        while (window._window.pollEvent(event)) {
            window._change = true;
            if (event.type == sf::Event::Closed) {
                window._window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                window._window.setMouseCursorVisible(false);
                settings.mouseHidden = true;
            } else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window._window.setMouseCursorVisible(true);
                        settings.mouseHidden = false;
                        break;
                    case sf::Keyboard::W:
                        dir += {1.0, 0.0, 0.0};
                        break;
                    case sf::Keyboard::A:
                        dir += {0.0, -1.0, 0.0};
                        break;
                    case sf::Keyboard::S:
                        dir += {-1.0, 0.0, 0.0};
                        break;
                    case sf::Keyboard::D:
                        dir += {0.0, 1.0, 0.0};
                        break;
                    case sf::Keyboard::Space:
                        settings.pos.z -= settings.speed;
                        break;
                    case sf::Keyboard::C:
                        settings.pos.z += settings.speed;
                        break;
                    case sf::Keyboard::Left:
                        settings.window_step_x -= settings.window_step;
                        break;
                    case sf::Keyboard::Right:
                        settings.window_step_x += settings.window_step;
                        break;
                    case sf::Keyboard::Up:
                        settings.window_step_y -= settings.window_step;
                        break;
                    case sf::Keyboard::Down:
                        settings.window_step_y += settings.window_step;
                        break;
                    case sf::Keyboard::Period:
                        settings.offset.x += settings.offset_step;
                        break;
                    case sf::Keyboard::Comma:
                        settings.offset.x -= settings.offset_step;
                        break;
                    case sf::Keyboard::Quote:
                        settings.offset.y += settings.offset_step;
                        break;
                    case sf::Keyboard::Semicolon:
                        settings.offset.y -= settings.offset_step;
                        break;
                    case sf::Keyboard::LBracket:
                        settings.offset.z += settings.offset_step;
                        break;
                    case sf::Keyboard::RBracket:
                        settings.offset.z -= settings.offset_step;
                        break;
                    case sf::Keyboard::Slash:
                        settings.offset = {1.0, 1.0, 1.0};
                        break;
                    default:
                        break;
                }
            }
        }
        if (settings.mouseHidden && window._change) {
            float mx = (float(settings.window_step_x) / float(settings.window_w) - 0.5f);
            float my = (float(settings.window_step_y) / float(settings.window_h) - 0.5f);
            sf::Vector3f dirTemp;
            dirTemp.z = dir.z * std::cos(-my) - dir.x * std::sin(-my);
            dirTemp.x = dir.z * std::sin(-my) + dir.x * std::cos(-my);
            dirTemp.y = dir.y;
            dir.x = dirTemp.x * std::cos(mx) - dirTemp.y * std::sin(mx);
            dir.y = dirTemp.x * std::sin(mx) + dirTemp.y * std::cos(mx);
            dir.z = dirTemp.z;
            settings.pos += dir * settings.speed;

            window._shader.setUniform("u_offset", settings.offset);
            window._shader.setUniform("u_pos", settings.pos);
            window._shader.setUniform("u_angle", sf::Vector2f(mx, my));
            window._shader.setUniform("u_seed1",
                                      sf::Vector2f((float) window._dist(window._e2), (float) window._dist(window._e2)) *
                                      999.0f);
            window._shader.setUniform("u_seed2",
                                      sf::Vector2f((float) window._dist(window._e2), (float) window._dist(window._e2)) *
                                      999.0f);
            window._window.draw(window._emptySprite, &window._shader);
            window._window.display();
        }
        window._change = false;
    }
}
