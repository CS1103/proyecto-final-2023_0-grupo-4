#include "TextBox.hpp"

#include <utility>

TextBox::TextBox(const rl::Vector2 &position, std::function<bool()> validator,
                 rl::Font &font)
    : m_text(font), m_rect(rl::Rectangle(position)),
      m_validator(std::move(validator)) {}

void TextBox::Draw() const {
  m_rect.Draw(WHITE);
  Utils::Vector2I textPosition = m_rect.GetPosition() =
}

bool TextBox::isClicked() const {}

void TextBox::setFocus(bool focus) {}

rl::Font &TextBox::defaultFont() {
  static rl::Font default_font(DEFAULT_FONT_PATH.data(), // NOLINT
                               DEFAULT_FONT_SIZE, nullptr, DEFAULT_MAX_TEXT);
  return default_font;
}
