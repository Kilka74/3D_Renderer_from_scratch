#include "../headers/KeyboardHandler.hpp"


KeyboardHandler::KeyboardHandler(
    sf::RenderWindow& window,
    Settings& current_settings,
    sf::Vector3f& dir, 
    const Settings& base_settings) :
    _window(window),
    _current_settings(current_settings),
    _dir(dir),
    _base_settings(base_settings)
    {}


void KeyboardHandler::handle(const sf::Keyboard::Key& code) {
    switch (code) {
        case sf::Keyboard::Escape:
            _window.setMouseCursorVisible(true);
            _current_settings.mouseHidden = false;
            break;
        case sf::Keyboard::W:
            _dir += {1.0, 0.0, 0.0};
            break;
        case sf::Keyboard::A:
            _dir += {0.0, -1.0, 0.0};
            break;
        case sf::Keyboard::S:
            _dir += {-1.0, 0.0, 0.0};
            break;
        case sf::Keyboard::D:
            _dir += {0.0, 1.0, 0.0};
            break;
        case sf::Keyboard::Space:
            _current_settings.pos.z -= _current_settings.speed;
            break;
        case sf::Keyboard::C:
            _current_settings.pos.z += _current_settings.speed;
            break;
        case sf::Keyboard::Left:
            _current_settings.window_step_x -= _current_settings.window_step;
            break;
        case sf::Keyboard::Right:
            _current_settings.window_step_x += _current_settings.window_step;
            break;
        case sf::Keyboard::Up:
            _current_settings.window_step_y -= _current_settings.window_step;
            break;
        case sf::Keyboard::Down:
            _current_settings.window_step_y += _current_settings.window_step;
            break;
        case sf::Keyboard::Enter:
            _current_settings = _base_settings;
            break;
        case sf::Keyboard::Period:
            _current_settings.offset.x += _current_settings.offset_step;
            break;
        case sf::Keyboard::Comma:
            _current_settings.offset.x -= _current_settings.offset_step;
            break;
        case sf::Keyboard::Quote:
            _current_settings.offset.y += _current_settings.offset_step;
            break;
        case sf::Keyboard::Semicolon:
            _current_settings.offset.y -= _current_settings.offset_step;
            break;
        case sf::Keyboard::LBracket:
            _current_settings.offset.z += _current_settings.offset_step;
            break;
        case sf::Keyboard::RBracket:
            _current_settings.offset.z -= _current_settings.offset_step;
            break;
        case sf::Keyboard::Slash:
            _current_settings.offset = {1.0, 1.0, 1.0};
            break;
        default:
            break;
    }
}
