#ifndef BUTTON_BUILDER_HPP
#define BUTTON_BUILDER_HPP

#include "TextBuilder.hpp"
#include "Vector2I.hpp"
#include <raylib-cpp.hpp>

constexpr std::string_view DEFAULT_BUTTON_TEXTURE_PATH = "PATH";

struct ButtonBuilder : public TextBuilder {

  raylib::Texture &texture = DefaultButtonTexture();

  // Setters
  ButtonBuilder(const std::string &text, const Utils::Vector2I &pos);

  // ButtonBuilder &Pos();
  ButtonBuilder &Pos(Utils::Vector2I vect2);

  ButtonBuilder &Text(const std::string &text);

  // ButtonBuilder &Texture();
  ButtonBuilder &Texture(raylib::Texture &texture);

  /*
ButtonBuilder() : texture(defaultButtonTexture()) {}
raylib::Texture &texture;
raylib::Text text;
Utils::Vector2I pos{};*/

  inline static raylib::Texture &DefaultButtonTexture() {
    static raylib::Texture s_texture(
        "../src/assets/Textures/test_old_button.png");
    return s_texture;
  }
};

#endif // !BUTTON_BUILDER_HPP
