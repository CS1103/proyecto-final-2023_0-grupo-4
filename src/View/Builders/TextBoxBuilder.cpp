#include "TextBoxBuilder.hpp"

#include <utility>

// TextBoxBuilder::TextBoxBuilder(
//     std::function<bool(const std::string &)> _validator)
//     : validator(std::move(_validator)) {}

TextBoxBuilder &TextBoxBuilder::Pos(const rl::Vector2 &_pos) {
  pos = _pos;
  return *this;
}
TextBoxBuilder &TextBoxBuilder::Size(const rl::Vector2 &_size) {
  size = _size;
  return *this;
}
TextBoxBuilder &TextBoxBuilder::Text(const rl::Text &_text) {
  text = _text;
  return *this;
}
TextBoxBuilder &
TextBoxBuilder::Validator(std::function<bool(const std::string &)> _validator) {
  validator = std::move(_validator);
  return *this;
}
