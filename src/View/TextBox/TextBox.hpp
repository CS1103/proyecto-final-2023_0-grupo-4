#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include "ViewUtils.hpp"
#include <cstdint>
#include <functional>
#include <raylib-cpp.hpp>
namespace rl = raylib;

constexpr std::string_view DEFAULT_FONT_PATH = "../src/assets/fonts/mecha.png";
constexpr int DEFAULT_FONT_SIZE = 20;
constexpr int DEFAULT_MAX_TEXT = 20;

class TextBox {
public:
  TextBox(const rl::Vector2 &position, std::function<bool()> validator,
          rl::Font &font = defaultFont());
  TextBox(const int &xPos, const int &yPos,
          const std::function<bool()> &validator,
          rl::Font &font = defaultFont());

  void Draw() const;

  [[nodiscard]] bool isClicked() const;

  void setFocus(bool focus);

  [[nodiscard]] inline rl::Vector2 GetSize() const;

  void setPosition(Utils::Vector2I pos);

  [[nodiscard]] std::string getText() const;

  [[nodiscard]] bool textIsValid();

  void handleInput();

private:
  rl::Text m_text;
  rl::Rectangle m_rect;
  std::function<bool()> m_validator;
  bool m_focus = false;

  /*

   bg color: rl::Color
   position
   validator: std::function<bool()>
  */

  static rl::Font &defaultFont();
};

#endif // !TEXT_BOX_HPP
