#ifndef TEXT_BUILDER_HPP
#define TEXT_BUILDER_HPP

#include "Vector2I.hpp"
#include <Font.hpp>
#include <Text.hpp>

constexpr int DEFAULT_FONT_SIZE = 16;
constexpr std::string_view DEFAULT_TEXT_FONT_PATH = "PATH";

class TextBuilder {

private:
  int fontSize = DEFAULT_FONT_SIZE;
  raylib::Color color = raylib::WHITE;
  raylib::Font font = DefaultTextFont();

protected:
  std::string text;
  Utils::Vector2I position;

public:
  TextBuilder(const std::string &text, const Utils::Vector2I &pos);

  TextBuilder &Text(std::string);

  TextBuilder &Position(Utils::Vector2I position);

  TextBuilder &FontSize(int fontSize);

  TextBuilder &Color(raylib::Color color);

  TextBuilder &Font(raylib::Font &font);
  TextBuilder &Font(const std::string &fontPath);
  TextBuilder &Font(const ::Image &image);

private:
  inline static raylib::Font DefaultTextFont() {
    // TODO(Kevin):
  }
};
#endif // !TEXT_BUILDER_HPP
