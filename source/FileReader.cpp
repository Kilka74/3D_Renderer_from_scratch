#include "../headers/FileReader.hpp"
#include <fstream>

Settings FileReader::get_settings(const std::string &filename) {
    Settings ans;
    std::string str;
    std::ifstream in(filename);
    for (int i = 0; i < 9; ++i) {
        in >> str;
        if (str == "window_size") {
            in >> ans.window_w >> ans.window_h;
        } else if (str == "speed") {
            in >> ans.speed;
        } else if (str == "offset_step") {
            in >> ans.offset_step;
        } else if (str == "window_step") {
            in >> ans.window_step;
        } else if (str == "samples") {
            in >> ans.samples;
            if (ans.samples < 1) {
                ans.samples = 1;
            }
        } else if (str == "references") {
            in >> ans.max_ref;
            if (ans.max_ref < 0) {
                ans.max_ref = 0;
            }
        } else if (str == "distance") {
            in >> ans.max_dist;
        } else if (str == "start_pos") {
            in >> ans.pos.x >> ans.pos.y >> ans.pos.z;
            ans.pos.z *= -1;
        } else if (str == "light") {
            in >> ans.lightPos.x >> ans.lightPos.y;
        }
    }
    ans.window_step_x = ans.window_w / 2;
    ans.window_step_y = ans.window_h / 2;
    ans.mouseHidden = true;
    ans.offset = {1.0, 1.0, 1.0};
    in.close();
    return ans;
}

World FileReader::get_world(const std::string &filename) {
    World ans;
    std::ifstream in(filename);
    int count;
    std::string name;
    in >> count;
    for (int i = 0; i < count; ++i) {
        in >> name;
        if (name == "sph") {
            sf::Glsl::Vec4 cord, col;
            in >> cord.x >> cord.y >> cord.z >> cord.w;
            cord.z *= -1;
            in >> col.x >> col.y >> col.z >> col.w;
            ans.sph_cord.push_back(cord);
            ans.sph_col.push_back(col);
        } else if (name == "box") {
            sf::Glsl::Vec4 col;
            sf::Glsl::Vec3 cord, size;
            in >> cord.x >> cord.y >> cord.z >> size.x >> size.y >> size.z;
            cord.z *= -1;
            in >> col.x >> col.y >> col.z >> col.w;
            ans.box_cord.push_back(cord);
            ans.box_cord.push_back(size);
            ans.box_col.push_back(col);
        } else if (name == "tri") {
            sf::Glsl::Vec3 v0, v1, v2;
            sf::Glsl::Vec4 col;
            in >> v0.x >> v0.y >> v0.z >> v1.x >> v1.y >> v1.z >> v2.x >> v2.y >> v2.z;
            v0.z *= -1;
            v1.z *= -1;
            v2.z *= -1;
            in >> col.x >> col.y >> col.z >> col.w;
            ans.tri_cord.push_back(sf::Glsl::Mat3({v0.x, v0.y, v0.z,
                                               v1.x, v1.y, v1.z,
                                               v2.x, v2.y, v2.z}));
            ans.tri_col.push_back(col);
        } else if (name == "pla") {
            in >> ans.pla_norm.x >> ans.pla_norm.y >> ans.pla_norm.z;
            ans.pla_norm.z *= -1;
            in >> ans.pla_col.x >> ans.pla_col.y >> ans.pla_col.z >> ans.pla_col.w;
        } else {
            break;
        }
    }
    in.close();
    return ans;
}
