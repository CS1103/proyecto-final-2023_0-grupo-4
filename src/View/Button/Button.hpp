// NOLINTBEGIN (readability-identifier-naming)
#ifndef BUTTON_H
#define BUTTON_H

#include <optional>
#include <raylib-cpp.hpp>
#include <string_view>
#include <vector>

constexpr std::string_view DEFAULT_FONT_PATH =
    "../src/assets/fonts/alpha_beta.png";

constexpr std::string_view DEFAULT_TEXTURE_PATH =
    "../src/assets/Textures/test_old_button.png";

constexpr int DEFAULT_FONT_SIZE = 20;
constexpr int DEFAULT_MAX_TEXT = 50;

namespace rl = raylib;

// ignore invalid case style
class Button {
public:
  Button() = delete;

  explicit Button(const std::string_view &text, rl::Texture &texture,
                  const float &fontSize = DEFAULT_FONT_SIZE,
                  const rl::Color &color = WHITE);
  explicit Button(const std::string_view &text,
                  float fontSize = DEFAULT_FONT_SIZE,
                  const rl::Color &color = WHITE);
  // effects: std::string_view
  // customFont rl::Font&

  void Draw(const int &posX = 0, const int &posY = 0) const;

  [[nodiscard]] bool isClicked(const int &posX, const int &posY) const;

  [[nodiscard]] inline bool isClicked(const rl::Vector2 &pos) const {
    return isClicked(static_cast<int>(pos.x), static_cast<int>(pos.y));
  }

  inline void Draw(const rl::Vector2 &pos) const {
    this->Draw(static_cast<int>(pos.x), static_cast<int>(pos.y));
  }

  [[nodiscard]] inline rl::Vector2 GetSize() const {
    // if (m_texture.has_value()) {
    //   return m_texture.value()();
    // }
    // return defaultTexture().GetSize();

    // Funcionara? xd
    return m_texture.GetSize();
  }

private:
  rl::Text m_text;
  rl::Texture &m_texture;

  inline static rl::Texture &defaultTexture() {
    static rl::Texture s_texture(
        "../src/assets/Textures/test_old_button.png"); // NOLINT
    return s_texture;
  }

  inline static rl::Font &defaultFont() {
    static rl::Font default_font(DEFAULT_FONT_PATH.data(),
                                 DEFAULT_FONT_SIZE, // NOLINT
                                 nullptr, DEFAULT_MAX_TEXT);
    return default_font;
  }
};

#endif // !BUTTON_H
// NOLINTEND (readability-identifier-naming)
