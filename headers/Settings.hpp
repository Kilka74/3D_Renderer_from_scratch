#pragma once
#include <SFML/Graphics.hpp>
//#include "FileReader.hpp"

struct SettingsImage {
    int window_w, window_h, window_step, samples, max_ref, window_step_x, window_step_y;
    bool mouseHidden;
    float speed, offset_step, max_dist;
    sf::Vector3f pos, offset;
    sf::Vector2f lightPos;
};

class Settings {
    int window_w, window_h, window_step, samples, max_ref, window_step_x, window_step_y;
    bool mouseHidden;
    float speed, offset_step, max_dist;
    sf::Vector3f pos, offset;
    sf::Vector2f lightPos;
    sf::Vector3f dir = sf::Vector3f(0.0f, 0.0f, 0.0f);

public:
    explicit Settings(const SettingsImage& image) :
        window_w(image.window_w),
        window_h(image.window_h),
        window_step(image.window_step),
        samples(image.samples),
        max_ref(image.max_ref),
        window_step_x(image.window_step_x),
        window_step_y(image.window_step_y),
        mouseHidden(image.mouseHidden),
        speed(image.speed),
        offset_step(image.offset_step),
        max_dist(image.max_dist),
        pos(image.pos),
        offset(image.offset),
        lightPos(image.lightPos) {}

    void HideMouse();
    void ShowMouse();
    void RotateLeft();
    void RotateRight();
    void RotateUp();
    void RotateDown();
    void ShiftUp();
    void ShiftDown();
    void ObserverCloser();
    void ObserverAway();

    void Distorsion1(); // Арслан зайди в ../source/KeyboardHandler.cpp посмотри что они делают
    void Distorsion2(); // и переименуй нормально я в душе не ебу че тут писать
    void Distorsion3();
    void Distorsion4();

    void Slash();       // и тут тоже хуй знает как это назвать

    bool IsMouseHidden();

    void ChangePos();

    void PrepareShader(sf::Shader& shader);

    sf::VideoMode CreateVideoMode() const;
    void CreateTexture(sf::RenderTexture& texture) const;

    void PrepareShader2(sf::Shader& shader) const; // и опять какой-то блядский нейминг

    void MoveForward();
    void MoveLeft();
    void MoveBack();
    void MoveRight();

    sf::Vector2f UpdatePicture();
    void ResetDir();
    void Reset();
};
