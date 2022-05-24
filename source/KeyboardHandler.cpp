#include "../headers/KeyboardHandler.hpp"
#include "../headers/Settings.hpp"


KeyboardHandler::KeyboardHandler(
    sf::RenderWindow& window,
    Settings& current_settings,
    sf::Vector3f& dir) :
    _window(window),
    _current_settings(current_settings),
    _dir(dir)
    {}


void KeyboardHandler::handle(const sf::Keyboard::Key& code) {
    switch (code) {
        case sf::Keyboard::Escape:
            _window.setMouseCursorVisible(true);
            _current_settings.ShowMouse();
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
            _current_settings.ShiftUp();
            break;
        case sf::Keyboard::C:
            _current_settings.ShiftDown();
            break;
        case sf::Keyboard::Left:
            _current_settings.RotateLeft();
            break;
        case sf::Keyboard::Right:
            _current_settings.RotateRight();
            break;
        case sf::Keyboard::Up:
            _current_settings.RotateUp();
            break;
        case sf::Keyboard::Down:
            _current_settings.RotateDown();
            break;
        case sf::Keyboard::Period:
            _current_settings.ObserverAway();
            break;
        case sf::Keyboard::Comma:
            _current_settings.ObserverCloser();
            break;
        case sf::Keyboard::Quote:
            _current_settings.Distorsion1();
            break;
        case sf::Keyboard::Semicolon:
            _current_settings.Distorsion2();
            break;
        case sf::Keyboard::LBracket:
            _current_settings.Distorsion3();
            break;
        case sf::Keyboard::RBracket:
            _current_settings.Distorsion4();
            break;
        case sf::Keyboard::Slash:
            _current_settings.Slash();
            break;
        default:
            break;
    }
}
