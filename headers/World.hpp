#pragma once
#include <SFML/Graphics.hpp>

struct WorldImage {
    sf::Glsl::Vec3 pla_norm;
    sf::Glsl::Vec4 pla_col;
    std::vector<sf::Glsl::Vec4> sph_cord;
    std::vector<sf::Glsl::Vec4> sph_col;
    std::vector<sf::Glsl::Vec3> box_cord;
    std::vector<sf::Glsl::Vec4> box_col;
    std::vector<sf::Glsl::Mat3> tri_cord;
    std::vector<sf::Glsl::Vec4> tri_col;
};

class World {
    sf::Glsl::Vec3 pla_norm;
    sf::Glsl::Vec4 pla_col;
    std::vector<sf::Glsl::Vec4> sph_cord;
    std::vector<sf::Glsl::Vec4> sph_col;
    std::vector<sf::Glsl::Vec3> box_cord;
    std::vector<sf::Glsl::Vec4> box_col;
    std::vector<sf::Glsl::Mat3> tri_cord;
    std::vector<sf::Glsl::Vec4> tri_col;

public:
    explicit World(const WorldImage& image) :
        pla_norm(image.pla_norm),     // вот тут надо помувать и в сеттинсах тоже но мне лень
        pla_col(image.pla_col),
        sph_cord(image.sph_cord),
        sph_col(image.sph_col),
        box_cord(image.box_cord),
        box_col(image.box_col),
        tri_cord(image.tri_cord),
        tri_col(image.tri_col) {}

    void LoadToShader(sf::Shader& shader) const;
};
