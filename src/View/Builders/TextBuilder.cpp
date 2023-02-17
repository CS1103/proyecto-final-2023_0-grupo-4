#include "TextBuilder.hpp"
#include <Font.hpp>
#include <Text.hpp>
#include <string>
#include <utility>

TextBuilder::TextBuilder(std::string _text) : text(std::move(_text)) {}

TextBuilder &TextBuilder::Text(std::string _text) {
  text = std::move(_text);
  return *this;
}
TextBuilder &TextBuilder::FontSize(float _fontSize) {
  fontSize = _fontSize;
  return *this;
}
TextBuilder &TextBuilder::Color(const rl::Color &_color) {
  color = _color;
  return *this;
}
TextBuilder &TextBuilder::Font(rl::Font &_font) {
  font = _font;
  return *this;
}
TextBuilder::operator rl::Text() const {
  rl::Text text_object(text, fontSize, color, font);
  return text_object;
}

// EXAMPLE
//  Inicializar la ventana de la aplicación
// Font customFont = LoadFont("path/to/font.ttf");

// TextBuilder builder;
// builder.setText("Hello World!")
//.FontSize(20)
//.Color(RED)
//.Font(customFont);
