#ifndef TEXT_BUILDER_HPP
#define TEXT_BUILDER_HPP

#include <Font.hpp>
#include <Text.hpp>

#include "resources.hpp"

namespace rl = raylib;

constexpr int DEFAULT_FONT_SIZE = 16;
constexpr std::string_view DEFAULT_TEXT_FONT_PATH =
    RESOURCE_PATH "fonts/fira_code_mono.ttf";

struct TextBuilder {

  float fontSize = DEFAULT_FONT_SIZE;
  rl::Color color = rl::WHITE;
  std::reference_wrapper<rl::Font> font = DefaultTextFont();

  // Obligatory
  std::string text;

  // Setters
  TextBuilder(std::string _text);
  TextBuilder() = default;

  TextBuilder &Text(std::string _text);

  TextBuilder &FontSize(float fontSize);

  TextBuilder &Color(const rl::Color &color);

  TextBuilder &Font(rl::Font &font);
  TextBuilder &Font(const std::string &fontPath);
  TextBuilder &Font(const ::Image &image);

  // casting to rl::Text
  operator rl::Text() const;

private:
  inline static rl::Font &DefaultTextFont() {
    static rl::Font font{DEFAULT_TEXT_FONT_PATH.data(), DEFAULT_FONT_SIZE};
    return font;
  }
};
#endif // !TEXT_BUILDER_HPP
