#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include "Vector2I.hpp"
#include "ViewUtils.hpp"

#include <functional>
#include <optional>

// raylib-pp
#include <Rectangle.hpp>
#include <Text.hpp>

namespace rl = raylib;

// constexpr std::string_view DEFAULT_FONT_PATH =
// "../src/assets/fonts/mecha.png"; constexpr int DEFAULT_FONT_SIZE = 20;
// constexpr int DEFAULT_MAX_TEXT = 20;

class TextBox {
public:
  explicit TextBox(const TextBoxBuilder &builder = Utils::DefaultTextBox());

  void Draw() const;

  void CheckFocus();

  [[nodiscard]] bool IsFocused() const;

  void SetFocus(bool focus);

  [[nodiscard]] inline rl::Vector2 GetSize() const;

  void SetPosition(Utils::Vector2I pos);

  [[nodiscard]] std::string GetText() const;

  [[nodiscard]] bool TextIsValid();

  std::optional<bool> HandleInput();

private:
  rl::Text m_text;
  rl::Rectangle m_rect;
  std::function<bool(std::string)> m_validator;
  bool m_focus = false;
};

#endif // !TEXT_BOX_HPP
