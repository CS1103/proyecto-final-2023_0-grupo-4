#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <functional>
#include <optional>

// raylib-pp
#include <Rectangle.hpp>
#include <Text.hpp>

namespace rl = raylib;

struct TextBoxBuilder {
  rl::Vector2 pos;
  rl::Text text = rl::Text();
  rl::Vector2 size = {100, 30};
  Color color = WHITE;
  std::function<bool(const std::string &)> validator =
      [](const std::string & /*str*/) { return true; };
  TextBoxBuilder(rl::Vector2 _pos) : pos(_pos) {}
};

struct TextBoxBuilder;

class TextBox {
public:
  TextBox(const TextBoxBuilder &builder);

  void Draw() const;

  void CheckFocus();

  [[nodiscard]] bool IsFocused() const;

  void SetFocus(bool focus);

  [[nodiscard]] inline rl::Vector2 GetSize() const;

  void SetPosition(rl::Vector2 pos);

  [[nodiscard]] std::string GetText() const;

  [[nodiscard]] bool TextIsValid();

  std::optional<bool> HandleInput();

  [[nodiscard]] bool CheckCollision(rl::Vector2 point) const;

private:
  rl::Text m_text;
  rl::Rectangle m_rect;
  Color m_color;
  std::function<bool(const std::string &)> m_validator;
  bool m_focus = false;
};

#endif // !TEXT_BOX_HPP
