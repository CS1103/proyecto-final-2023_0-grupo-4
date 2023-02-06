#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include "TextBoxBuilder.hpp"
#include "Vector2I.hpp"
#include <ViewUtils.hpp>
#include <cstdint>
#include <functional>
#include <raylib-cpp.hpp>
namespace rl = raylib;

constexpr std::string_view DEFAULT_FONT_PATH = "../src/assets/fonts/mecha.png";
constexpr int DEFAULT_FONT_SIZE = 20;
constexpr int DEFAULT_MAX_TEXT = 20;

class TextBox {
public:
  explicit TextBox(const TextBoxBuilder &builder = Utils::DEFAULT_TEXT_BOX);

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
};

#endif // !TEXT_BOX_HPP
