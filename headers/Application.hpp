#pragma once
#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <utility>
#include "Settings.hpp"


class Application {
    friend struct Window;

    const Settings base_settings;
    Settings curr_settings;
    sf::Glsl::Vec3 pla_norm;
    sf::Glsl::Vec4 pla_col;
    std::vector<sf::Glsl::Vec4> sph_cord;
    std::vector<sf::Glsl::Vec4> sph_col;
    std::vector<sf::Glsl::Vec3> box_cord;
    std::vector<sf::Glsl::Vec4> box_col;
    std::vector<sf::Glsl::Mat3> tri_cord;
    std::vector<sf::Glsl::Vec4> tri_col;
    const std::string shader_name;

public:
    explicit Application(const std::string &settings_file = "input",
             const std::string &objects_file = "objects",
             std::string shader_file = "Shader.frag") :
            base_settings(settings_file), shader_name(std::move(shader_file)) {
        curr_settings = base_settings;
        load_objects(objects_file);
    }
    void run();

private:
    void load_objects(const std::string &file);
};