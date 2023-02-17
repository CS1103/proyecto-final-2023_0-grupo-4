#include "ButtonBuilder.hpp"

ButtonBuilder &ButtonBuilder::Pos(const Utils::Vector2I &_pos) {
  pos = _pos;
  return *this;
}

ButtonBuilder &ButtonBuilder::Text(const std::string &_text) {
  text = _text;
  return *this;
}
ButtonBuilder &ButtonBuilder::Text(const rl::Text &_text) {
  text = _text.text;
  return *this;
}

ButtonBuilder &ButtonBuilder::Texture(rl::Texture &_texture) {
  texture = _texture;
  return *this;
}
