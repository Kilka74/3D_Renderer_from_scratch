#pragma once
#include <random>
#include "FileReader.hpp"

class Window {
    sf::RenderWindow _window;
    sf::Shader _shader;
    bool _change;
    bool _mouseHidden;
    std::uniform_real_distribution<> _dist;
    std::mt19937 _e2;
    sf::RenderTexture _emptyTexture;
    sf::Sprite _emptySprite;

public:
    Window(const Camera &camera, const World &world, const std::string &shader_name);
    void Redraw(const sf::Vector2f& vec, Camera& settings);
    void setMouseCursorVisible(bool flag);
    void StartChanges();
    void FinishChanges();
    bool NeedRedraw() const;
    bool IsOpen();
    bool PollEvent(sf::Event& event);
    void Close();
    void ReloadWorld(World& world);
};
