#include "TextBuilder.hpp"
#include <Font.hpp>
#include <Text.hpp>
#include <string>

TextBuilder &TextBuilder::Text(std::string text_) {
  this->text = text_;
  return *this;
}
TextBuilder &TextBuilder::Position(Vector2 position_) {
  this->position = position_;
  return *this;
}
TextBuilder &TextBuilder::FontSize(int fontSize_) {
  this->fontSize = fontSize_;
  return *this;
}
TextBuilder &TextBuilder::Color_(Color color_) {
  this->color = color_;
  return *this;
}
TextBuilder &TextBuilder::Font_(Font font_) {
  this->font = font_;
  return *this;
}

void TextBuilder::draw() {
  { DrawTextEx(font, text.c_str(), position, fontSize, 0.0f, color); }
}
// EXAMPLE
//  Inicializar la ventana de la aplicación
// Font customFont = LoadFont("path/to/font.ttf");

// TextBuilder builder;
// builder.setText("Hello World!")
//.Position({ 100, 100 })
//.FontSize(20)
//.Color(RED)
//.Font(customFont);
