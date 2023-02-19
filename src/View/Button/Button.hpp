#ifndef BUTTON_H
#define BUTTON_H

#include "ButtonBuilder.hpp"
#include <optional>
#include <string_view>
#include <vector>

namespace rl = raylib;

class Button {
public:
  Button(const ButtonBuilder &builder);

  void Draw() const;

  [[nodiscard]] bool IsClicked() const;

  [[nodiscard]] inline rl::Vector2 GetSize() const {
    return m_texture.GetSize();
  }

  void Highlight();
  void UnHighlight();

private:
  rl::Text m_text;
  rl::Texture &m_texture;
  Utils::Vector2I m_pos;
  bool is_selected;
};

#endif // !BUTTON_H
