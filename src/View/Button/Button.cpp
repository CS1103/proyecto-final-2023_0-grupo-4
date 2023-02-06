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

Button::Button(const std::string_view &text, rl::Texture &texture,
               const float &fontSize, const rl::Color &color)
    : m_text(rl::Text(text.data(), fontSize, color)), m_texture(texture) {

  ValidateSize(m_texture, m_text);
}

Button::Button(const std::string_view &text, float fontSize,
               const rl::Color &color)
    : m_text(rl::Text(text.data(), fontSize, color)),
      m_texture(Button::defaultTexture()) {

  ValidateSize(m_texture, m_text);
}

// Button::Button(std::string_view text, rl::Font &customFont) {}

void Button::Draw(const int &posX, const int &posY) const {

  Vector2I text_size = Vector2I(m_text.MeasureEx());
  Vector2I button_size = Vector2I(m_texture.GetSize());

  // clang-format off
  auto [text_x, text_y] = std::pair{
      posX +
          (button_size.x - text_size.x) / 2,
      posY +
          (button_size.y - text_size.y) / 2};
  // clang-format on

  m_texture.Draw(posX, posY);
  m_text.Draw(text_x, text_y);
}

bool Button::isClicked(const int &drawPosX, const int &drawPosY) const {

  if (!rl::Mouse::IsButtonPressed(MouseButton::MOUSE_LEFT_BUTTON)) {
    return false;
  }

  Vector2I click_pos = rl::Mouse::GetPosition();

  Vector2I button_size = m_texture.GetSize();
  auto button_end =
      Vector2I{drawPosX + button_size.x, drawPosY + button_size.y};

  return (click_pos.x >= drawPosX && click_pos.x <= button_end.x) &&
         (click_pos.y >= drawPosY && click_pos.y <= button_end.y);
}
