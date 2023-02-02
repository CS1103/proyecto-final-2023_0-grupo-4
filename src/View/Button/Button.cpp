#include "Button.hpp"

// Temporal
#include <iostream>

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

  auto text_size = m_text.MeasureEx();
  auto button_size = m_texture.GetSize();

  // clang-format off
  auto [text_x, text_y] = std::pair{
      posX +
          (static_cast<int>(button_size.x) - static_cast<int>(text_size.x)) / 2,
      posY +
          (static_cast<int>(button_size.y) - static_cast<int>(text_size.y)) / 2};
  // clang-format on

  m_texture.Draw(posX, posY);
  m_text.Draw(text_x, text_y);
}

bool Button::isClicked(const int &posX, const int &posY) const {

  if (!rl::Mouse::IsButtonPressed(MouseButton::MOUSE_LEFT_BUTTON)) {
    return false;
  }

  auto button_size = m_texture.GetSize();
  auto click_pos = rl::Mouse::GetPosition();

  std::cout << "Click pos: " << click_pos.x << ", " << click_pos.y << std::endl;

  // complicated stuff to check if click_pos is inside texture draw position
  // static_cast is used because rl::Vector2 is a float,
  // might not be needed, but affects performance?
  return static_cast<int>(click_pos.x) >= posX &&
         static_cast<int>(click_pos.x) <=
             posX + static_cast<int>(button_size.x) &&
         static_cast<int>(click_pos.y) >= posY &&
         static_cast<int>(click_pos.y) <=
             posY + static_cast<int>(button_size.y);
}
