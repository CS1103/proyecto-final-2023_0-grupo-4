#include "Button.hpp"

// Temporal
#include <iostream>

using Utils::Vector2I;

static bool ValidateSize(const rl::Texture &texture, const rl::Text &text) {

  const float TEXT_BUTTON_RATIO = 0.8F;

  raylib::Vector2 text_size = text.MeasureEx();
  raylib::Vector2 texture_size = texture.GetSize();

  if (text_size.x > texture_size.x * TEXT_BUTTON_RATIO) {
    std::cout << "Text is too long for the button" << std::endl;
    // throw std::runtime_error("Text is too long for the button");
    return false;
  }
  if (text_size.y > texture_size.y * TEXT_BUTTON_RATIO) {
    std::cout << "Text is too tall for the button" << std::endl;
    // throw std::runtime_error("Text is too tall for the button");
    return false;
  }
  return true;
}

Button::Button(const ButtonBuilder &builder)
    : m_text(builder.text), m_texture(builder.texture), m_pos(builder.pos) {
  ValidateSize(m_texture, m_text);
}

void Button::Draw() const {

  Vector2I text_size = Vector2I(m_text.MeasureEx());
  Vector2I button_size = Vector2I(m_texture.GetSize());

  auto [text_x, text_y] =
      std::pair{m_pos.x + (button_size.x - text_size.x) / 2,
                m_pos.y + (button_size.y - text_size.y) / 2};

  if (is_selected) {
    m_texture.Draw(m_pos, 0, 1, WHITE);
  } else {
    m_texture.Draw(m_pos, 0, 1, GRAY);
  }

  m_text.Draw(text_x, text_y);
}

bool Button::IsClicked() const {

  if (!rl::Mouse::IsButtonPressed(MouseButton::MOUSE_LEFT_BUTTON)) {
    return false;
  }

  Vector2I click_pos = rl::Mouse::GetPosition();

  Vector2I button_size = m_texture.GetSize();
  auto button_end = Vector2I{m_pos.x + button_size.x, m_pos.y + button_size.y};

  return (click_pos.x >= m_pos.x && click_pos.x <= button_end.x) &&
         (click_pos.y >= m_pos.y && click_pos.y <= button_end.y);
}

void Button::Highlight() { is_selected = true; }
void Button::UnHighlight() { is_selected = false; }
