#include "TextBox.hpp"

#include <utility>

// TextBox::TextBox(const rl::Vector2 &position, std::function<bool()>
// validator,
//                  rl::Font &font)
//     : m_text(font), m_rect(rl::Rectangle(position)),
//       m_validator(std::move(validator)) {}

void TextBox::Draw() const {
  m_rect.Draw(WHITE);
  Utils::Vector2I text_position =
      m_rect.GetPosition() + m_rect.GetSize() / 2 - m_text.MeasureEx() / 2;
  m_text.Draw(text_position);
}

bool TextBox::isClicked() const { return true; }

void TextBox::setFocus(bool focus) {}
