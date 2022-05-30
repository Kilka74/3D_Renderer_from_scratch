#include "../headers/KeyboardHandler.hpp"

void KeyboardHandler::handle(const sf::Keyboard::Key &code) {
    switch (code) {
        case sf::Keyboard::Escape:
            _window.setMouseCursorVisible(true);
            break;
        case sf::Keyboard::W:
            _camera.MoveForward();
            break;
        case sf::Keyboard::A:
            _camera.MoveLeft();
            break;
        case sf::Keyboard::S:
            _camera.MoveBack();
            break;
        case sf::Keyboard::D:
            _camera.MoveRight();
            break;
        case sf::Keyboard::Space:
            _camera.ShiftUp();
            break;
        case sf::Keyboard::C:
            _camera.ShiftDown();
            break;
        case sf::Keyboard::Left:
            _camera.RotateLeft();
            break;
        case sf::Keyboard::Right:
            _camera.RotateRight();
            break;
        case sf::Keyboard::Up:
            _camera.RotateUp();
            break;
        case sf::Keyboard::Down:
            _camera.RotateDown();
            break;
        case sf::Keyboard::Period:
            _camera.ObserverAway();
            break;
        case sf::Keyboard::Comma:
            _camera.ObserverCloser();
            break;
        case sf::Keyboard::Quote:
            _camera.ShrinkWidth();
            break;
        case sf::Keyboard::Semicolon:
            _camera.StretchWidth();
            break;
        case sf::Keyboard::LBracket:
            _camera.ShrinkHigh();
            break;
        case sf::Keyboard::RBracket:
            _camera.StretchHigh();
            break;
        case sf::Keyboard::Slash:
            _camera.ResetOffset();
            break;
        default:
            break;
    }
}
