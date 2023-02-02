#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <raylib-cpp.hpp>

namespace rl = raylib;

class Button {

public:
  void Draw(const int &pos_x, const int &pos_y) {
    sTexture().Draw(pos_x, pos_y);
  }
  Button() : m_texture(sTexture()) {}

private:
  inline static rl::Texture &sTexture() {
    static rl::Texture s_texture("../src/assets/Textures/test_old_button.png");
    return s_texture;
  }
  rl::Texture &m_texture;
};

#endif // !BUTTON_HPP
