#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <utility>


class Application {
private:
class Settings {
    public:
        int window_w, window_h, window_step, samples, max_ref, window_step_x, window_step_y;
        bool mouseHidden;
        float speed, offset_step, max_dist;
        sf::Vector3f pos, offset;
        sf::Vector2f lightPos;

        Settings() = default;

        explicit Settings(const std::string &file) {
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
    };

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