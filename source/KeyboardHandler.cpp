#include "../headers/KeyboardHandler.hpp"
#include <iostream>


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
        case sf::Keyboard::F1:
            figures[*cur_fig]->MoveBack();
            break;
        case sf::Keyboard::F2:
            figures[*cur_fig]->MoveForward();
            break;
        case sf::Keyboard::F3:
            figures[*cur_fig]->MoveLeft();
            break;
        case sf::Keyboard::F4:
            figures[*cur_fig]->MoveRight();
            break;
        case sf::Keyboard::F5:
            figures[*cur_fig]->MoveUp();
            break;
        case sf::Keyboard::F6:
            figures[*cur_fig]->MoveDown();
            break;
        case sf::Keyboard::Q:
            PrevFigure();
            break;
        case sf::Keyboard::E:
            NextFigure();
            break;
        default:
            break;
    }
}

void KeyboardHandler::NextFigure() {
    if (*cur_fig < figures.size() - 1) {
        (*cur_fig)++;
    } else {
        *cur_fig = 0;
    }
}

void KeyboardHandler::PrevFigure() {
    if (*cur_fig != 0) {
        (*cur_fig)--;
    } else {
        *cur_fig = figures.size() - 1;
    }
}
