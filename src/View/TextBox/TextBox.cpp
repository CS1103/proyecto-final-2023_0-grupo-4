#include "TextBox.hpp"

TextBox::TextBox(const TextBoxBuilder &builder)
    : m_text(builder.text), m_rect(builder.pos),
      m_validator(builder.validator) {}

void TextBox::Draw() const {
  m_rect.Draw(WHITE);
  Utils::Vector2I text_position =
      m_rect.GetPosition() + m_rect.GetSize() / 2 - m_text.MeasureEx() / 2;
  m_text.Draw(text_position);
}

void TextBox::CheckFocus() {

  bool mouse_on_rect = CheckCollisionPointRec(GetMousePosition(), m_rect);
  if (mouse_on_rect) {
    SetMouseCursor(MOUSE_CURSOR_IBEAM);
  }
  if (IsMouseButtonPressed(0)) {
    m_focus = mouse_on_rect;
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

constexpr int BACKSPACE = 8;
constexpr int ENTER = 13;
constexpr int ESC = 27;

/// Breve descripción, solo una línea, triple /
std::optional<bool> TextBox::HandleInput() {
  if (!m_focus) {
    return std::nullopt;
  }

  int key = GetKeyPressed();

  while (key != 0) {

    if (key == BACKSPACE) {
      m_text.SetText(m_text.GetText().substr(0, m_text.GetText().size() - 1));

    } else if (key == ENTER) {
      break;
    } else if (key == ESC) {
      m_focus = false;
      break;
    } else {
      m_text.SetText(m_text.GetText() + static_cast<char>(key));
    }
    key = GetKeyPressed();
  }

  return TextIsValid();
}
