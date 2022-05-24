#include "../headers/World.hpp"
#include "../headers/Sphere.hpp"
#include "../headers/Box.hpp"
#include "../headers/Triangle.hpp"
#include <memory>


void World::LoadToShader(sf::Shader& shader) const {
    shader.setUniform("u_pla_norm", pla_norm);
    shader.setUniform("u_pla_col", pla_col);
    shader.setUniform("u_sph_num", int(sph_col.size()));
    shader.setUniformArray("u_sph_cord", sph_cord.data(), sph_cord.size());
    shader.setUniformArray("u_sph_col", sph_col.data(), sph_col.size());
    shader.setUniform("u_box_num", int(box_col.size()));
    shader.setUniformArray("u_box_cord", box_cord.data(), box_cord.size());
    shader.setUniformArray("u_box_col", box_col.data(), box_col.size());
    shader.setUniform("u_tri_num", int(tri_col.size()));
    shader.setUniformArray("u_tri_cord", tri_cord.data(), tri_cord.size());
    shader.setUniformArray("u_tri_col", tri_col.data(), tri_col.size());
}

std::vector<std::shared_ptr<Figure>> World::Figures() {
    std::vector<std::shared_ptr<Figure>> ans;
    for (auto& v : sph_cord) {
        ans.push_back(std::make_shared<Sphere>(&v));
    }
    for (size_t i = 0; i < box_cord.size(); i+=2) {
        ans.push_back(std::make_shared<Box>(&box_cord[i]));
    }
    for (auto& v : tri_cord) {
        ans.push_back(std::make_shared<Triangle>(&v));
    }
    return ans;
}
