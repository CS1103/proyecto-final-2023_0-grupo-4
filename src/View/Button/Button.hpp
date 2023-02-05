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