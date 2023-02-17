#ifndef BUTTON_BUILDER_HPP
#define BUTTON_BUILDER_HPP

#include "TextBuilder.hpp"
#include "Vector2I.hpp"
#include <raylib-cpp.hpp>

#include "resources.hpp"

constexpr std::string_view DEFAULT_BUTTON_TEXTURE_PATH = "PATH";

namespace rl = raylib;

struct ButtonBuilder : public TextBuilder {

  std::reference_wrapper<rl::Texture> texture = DefaultButtonTexture();
  Utils::Vector2I pos{};

  ButtonBuilder() = default;
  ButtonBuilder(const std::string &_text, const Utils::Vector2I &_pos);
  ButtonBuilder(const rl::Text &_eext, const Utils::Vector2I &_pos);

  // Setters
  ButtonBuilder &Pos(const Utils::Vector2I &pos);

  ButtonBuilder &Text(const std::string &text);
  ButtonBuilder &Text(const rl::Text &text);

  ButtonBuilder &Texture(raylib::Texture &texture);

  ButtonBuilder &FontSize(const float &size);
  ButtonBuilder &Color(const rl::Color &color);

  /*
ButtonBuilder() : texture(defaultButtonTexture()) {}
raylib::Texture &texture;
raylib::Text text;
Utils::Vector2I pos{};*/

  inline static raylib::Texture &DefaultButtonTexture() {
    static raylib::Texture s_texture(RESOURCE_PATH
                                     "Textures/test_old_button.png");
    return s_texture;
  }
};

#endif // !BUTTON_BUILDER_HPP
