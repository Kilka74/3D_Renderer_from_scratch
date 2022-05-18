#include "../headers/Window.hpp"


Window::Window(Application& app) :
    _window(sf::VideoMode(app.curr_settings.window_w, app.curr_settings.window_h),
                            "Ray tracing",
                            sf::Style::Titlebar | sf::Style::Close), _shader() {
    _window.setFramerateLimit(40);
    _window.setMouseCursorVisible(false);
    sf::RenderTexture emptyTexture;
    emptyTexture.create(app.curr_settings.window_w, app.curr_settings.window_h);
    _emptySprite = sf::Sprite(emptyTexture.getTexture());
    _shader.loadFromFile(app.shader_name, sf::Shader::Fragment);
    _shader.setUniform("u_resolution", sf::Vector2f(float(app.curr_settings.window_w), float(app.curr_settings.window_h)));
    _shader.setUniform("u_light", app.curr_settings.lightPos);
    _shader.setUniform("u_samples", app.curr_settings.samples);
    _shader.setUniform("u_refs", app.curr_settings.max_ref);
    _shader.setUniform("u_max_dist", app.curr_settings.max_dist);
    _shader.setUniform("u_pla_norm", app.pla_norm);
    _shader.setUniform("u_pla_col", app.pla_col);
    std::random_device RandomGenerator;
    _e2 = std::mt19937(RandomGenerator());
    _dist = std::uniform_real_distribution<>(0.0f, 1.0f);
    _shader.setUniform("u_sph_num", int(app.sph_col.size()));
    _shader.setUniformArray("u_sph_cord", app.sph_cord.data(), app.sph_cord.size());
    _shader.setUniformArray("u_sph_col", app.sph_col.data(), app.sph_col.size());
    _shader.setUniform("u_box_num", int(app.box_col.size()));
    _shader.setUniformArray("u_box_cord", app.box_cord.data(), app.box_cord.size());
    _shader.setUniformArray("u_box_col", app.box_col.data(), app.box_col.size());
    _shader.setUniform("u_tri_num", int(app.tri_col.size()));
    _shader.setUniformArray("u_tri_cord", app.tri_cord.data(), app.tri_cord.size());
    _shader.setUniformArray("u_tri_col", app.tri_col.data(), app.tri_col.size());
    _change = true;
}
