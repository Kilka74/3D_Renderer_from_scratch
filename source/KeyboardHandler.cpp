#include "../headers/KeyboardHandler.hpp"

void KeyboardHandler::handle(const sf::Keyboard::Key &code) {
    switch (code) {
        case sf::Keyboard::Escape:
            _window.setMouseCursorVisible(true);
            break;
        case sf::Keyboard::W:
            _current_settings.MoveForward();
            break;
        case sf::Keyboard::A:
            _current_settings.MoveLeft();
            break;
        case sf::Keyboard::S:
            _current_settings.MoveBack();
            break;
        case sf::Keyboard::D:
            _current_settings.MoveRight();
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
            _current_settings.ShrinkWidth();
            break;
        case sf::Keyboard::Semicolon:
            _current_settings.StretchWidth();
            break;
        case sf::Keyboard::LBracket:
            _current_settings.ShrinkHigh();
            break;
        case sf::Keyboard::RBracket:
            _current_settings.StretchHigh();
            break;
        case sf::Keyboard::Slash:
            _current_settings.ResetOffset();
            break;
        default:
            break;
    }
}
