#include "../headers/Settings.hpp"
#include <fstream>


Settings::Settings(const std::string& file) {
    std::string str;
    std::ifstream in(file);
    for (int i = 0; i < 9; ++i) {
        in >> str;
        if (str == "window_size") {
            in >> window_w >> window_h;
        } else if (str == "speed") {
            in >> speed;
        } else if (str == "offset_step") {
            in >> offset_step;
        } else if (str == "window_step") {
            in >> window_step;
        } else if (str == "samples") {
            in >> samples;
            if (samples < 1) {
                samples = 1;
            }
        } else if (str == "references") {
            in >> max_ref;
            if (max_ref < 0) {
                max_ref = 0;
            }
        } else if (str == "distance") {
            in >> max_dist;
        } else if (str == "start_pos") {
            in >> pos.x >> pos.y >> pos.z;
            pos.z *= -1;
        } else if (str == "light") {
            in >> lightPos.x >> lightPos.y;
        }
    }
    window_step_x = window_w / 2;
    window_step_y = window_h / 2;
    mouseHidden = true;
    offset = {1.0, 1.0, 1.0};
    in.close();
}
