#ifndef BUTTON_BUILDER_HPP
#define BUTTON_BUILDER_HPP

#include "Vector2I.hpp"
#include <raylib-cpp.hpp>
class Button;

struct ButtonBuilder {

  ButtonBuilder() : texture(defaultButtonTexture()) {}

  raylib::Texture &texture;
  raylib::Text text;
  Utils::Vector2I pos{};

  operator Button() const;

private:
  inline static raylib::Texture &defaultButtonTexture() {
    static raylib::Texture s_texture(
        "../src/assets/Textures/test_old_button.png");
    return s_texture;
  }
};

#endif // !BUTTON_BUILDER_HPP
