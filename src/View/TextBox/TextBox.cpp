#include "TextBox.hpp"

// testing
#include <iostream>

TextBox::TextBox(const TextBoxBuilder &builder)
    : m_text(builder.text), m_rect(builder.pos, builder.size),
      m_color(builder.color), m_validator(builder.validator) {

  m_text.SetText("a");
  auto max_width = m_rect.width;
  auto char_width = m_text.Measure();

  m_maxLength =
      static_cast<uint8_t>(static_cast<int>(max_width) / char_width - 1);
  m_text.SetText("");
}

void TextBox::Draw() const {

  m_rect.Draw(m_color);

  auto size = m_text.MeasureEx();

  Utils::Vector2I text_position =
      m_rect.GetPosition() + m_rect.GetSize() / 2 - m_text.MeasureEx() / 2;
  m_text.Draw(text_position);
}

void TextBox::CheckFocus() {

  if (IsMouseButtonPressed(0)) {
    m_focus = m_rect.CheckCollision(GetMousePosition());
  }
}
bool TextBox::IsFocused() const { return m_focus; }

inline rl::Vector2 TextBox::GetSize() const { return m_rect.GetSize(); }

void TextBox::SetPosition(Utils::Vector2I pos) { m_rect.SetPosition(pos); }

std::string TextBox::GetText() const { return m_text.GetText(); }

/************************************************
Detailed descripción: TextBox::TextIsValid
option 1
 ***********************************************/
[[nodiscard]] bool TextBox::TextIsValid() {
  return m_validator(m_text.GetText());
}

/// Breve descripción, solo una línea, triple /
void TextBox::HandleInput() {

  if (!m_focus) {
    return;
  }

  int key = GetCharPressed();

  while (key > 0) {

    auto text = m_text.GetText();

    // NOTE: Only allow keys in range [32..125]
    if ((key >= 32) && (key <= 125) && (text.size() < m_maxLength)) {

      m_text.SetText(m_text.GetText() + static_cast<char>(key));
    }

    key = GetCharPressed();
  }
  if (IsKeyPressed(KEY_BACKSPACE)) {
    m_text.SetText(m_text.GetText().substr(0, m_text.GetText().size() - 1));
  }
}

bool TextBox::CheckCollision(Utils::Vector2I point) const {
  return m_rect.CheckCollision(point);
}
