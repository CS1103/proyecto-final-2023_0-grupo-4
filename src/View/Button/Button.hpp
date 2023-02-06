// NOLINTBEGIN (readability-identifier-naming)
#ifndef BUTTON_H
#define BUTTON_H

#include "ViewUtils/ViewUtils.hpp"
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
  explicit Button(const std::string_view &text, rl::Texture &texture,
                  const float &fontSize = DEFAULT_FONT_SIZE,
                  const rl::Color &color = WHITE);
  explicit Button(const std::string_view &text,
                  float fontSize = DEFAULT_FONT_SIZE,
                  const rl::Color &color = WHITE);

  // PRESET_TEXT_CONFIGS

  // Text: std::string_view
  // fontSize: float
  // Color: raylib::Color
  // spacing: float
  // CUSTOM FONTS
  // FontPath: std::string_view
  // FontPath: PRESET_FONTS

  void Draw(const int &posX, const int &posY) const;

  [[nodiscard]] bool isClicked(const int &posX, const int &posY) const;

  [[nodiscard]] inline bool isClicked(const Utils::Vector2I &pos) const {
    return isClicked(pos.x, pos.y);
  }

  inline void Draw(const Utils::Vector2I &pos) const {
    this->Draw(pos.x, pos.y);
  }

  [[nodiscard]] inline rl::Vector2 GetSize() const {
    return m_texture.GetSize();
  }

private:
  rl::Text m_text;
  rl::Texture &m_texture;
  int xPos;
  int yPos;

  inline static rl::Texture &defaultButtonTexture() {
    static rl::Texture s_texture(
        "../src/assets/Textures/test_old_button.png"); // NOLINT
    return s_texture;
  }
};

#endif // !BUTTON_H
// NOLINTEND (readability-identifier-naming)
//Button Builder Pattern
typedef struct Button_n {
    Rectangle rect; //params (x,y,width,height)
    Color color;
    Color textColor;
    const char* text;
    bool isPressed;
} Button_n;
typedef struct ButtonBuilder {
    Rectangle rect;
    Color color;
    Color textColor;
    const char* text;
    bool isPressed;
    ButtonBuilder() : rect({ 0, 0, 0, 0 }), color({ 0, 0, 0, 0 }), textColor({ 0, 0, 0, 0 }), text(NULL), isPressed(false) {}
    ButtonBuilder& setRect(Rectangle r) { rect = r; return *this; }
    ButtonBuilder& setColor(Color c) { color = c; return *this; }
    ButtonBuilder& setTextColor(Color c) { textColor = c; return *this; }
    ButtonBuilder& setText(const char* t) { text = t; return *this; }
    Button_n build() {
        Button_n b;
        b.rect = rect;
        b.color = color;
        b.textColor = textColor;
        b.text = text;
        b.isPressed = isPressed;
        return b;
    }
} ButtonBuilder;

/* Example of button builder
  Button_n button = ButtonBuilder().setRect({ 200, 200, 200, 80 })
                    .setColor({ 200, 100, 50, 255 })
                    .setTextColor({ 0, 0, 0, 255 })
                    .setText("Click me!").build();

    Drawing button function left
 */