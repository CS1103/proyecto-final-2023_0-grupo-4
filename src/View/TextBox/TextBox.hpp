#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include "TextBoxBuilder.hpp"
#include "Vector2I.hpp"

#include <functional>
#include <optional>

// raylib-pp
#include <Rectangle.hpp>
#include <Text.hpp>

namespace rl = raylib;

class TextBox {
public:
  TextBox(const TextBoxBuilder &builder);

  void Draw() const;

  void CheckFocus();

  [[nodiscard]] bool IsFocused() const;

  void SetFocus(bool focus);

  [[nodiscard]] inline rl::Vector2 GetSize() const;

  void SetPosition(Utils::Vector2I pos);

  [[nodiscard]] std::string GetText() const;

  [[nodiscard]] bool TextIsValid();

  std::optional<bool> HandleInput();

  [[nodiscard]] bool CheckCollision(Utils::Vector2I point) const;

private:
  rl::Text m_text;
  rl::Rectangle m_rect;
  Color m_color;
  std::function<bool(const std::string &)> m_validator;
  bool m_focus = false;
  uint8_t m_maxLength;
};

#endif // !TEXT_BOX_HPP
