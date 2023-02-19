#include "TextBoxBuilder.hpp"

TextBoxBuilder &TextBoxBuilder::Pos(const rl::Vector2 &_pos) {
  pos = _pos;
  return *this;
}
TextBoxBuilder &TextBoxBuilder::Size(const rl::Vector2 &_size) {
  size = _size;
  return *this;
}
TextBoxBuilder::TextBoxBuilder(
    const std::function<bool(const std::string &)> &validator)
    : validator(validator) {}
TextBoxBuilder &TextBoxBuilder::Text(const rl::Text &_text) {
  text = _text;
  return *this;
}
