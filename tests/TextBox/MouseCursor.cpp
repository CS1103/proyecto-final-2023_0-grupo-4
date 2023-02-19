#include "TextBox.hpp"
#include <chrono>
#include <functional>
#include <iostream>
#include <raylib-cpp.hpp>
#include <thread>

namespace rl = raylib;

rl::Window window(800, 450, "raylib [text] example - text box input");

struct Vector2I {
  int x;
  int y;
};
// TextBox::TextBox(const TextBoxBuilder &builder)
//     : m_text(builder.text), m_rect(builder.pos, builder.size),
//       m_color(builder.color), m_validator(builder.validator) {}

static rl::Vector2 calc(int x, int y) {
  return {static_cast<float>(x), static_cast<float>(y)};
}

int main() {

  window.SetTargetFPS(10);

  const rl::Vector2 WIDTH_POSITION = calc(65 - 10, 40);
  const rl::Vector2 HEIGHT_POSITION = calc(65 + 10, 40);

  auto size_validator = [](const std::string &str) {
    if (str.empty() || str.size() > 3) {
      return false;
    }
    return std::all_of(str.begin(), str.end(), ::isdigit);
  };

  TextBox width_box = TextBoxBuilder(WIDTH_POSITION);
  TextBox height_box = TextBoxBuilder(HEIGHT_POSITION);

  std::optional<uint8_t> width;
  std::optional<uint8_t> height;

  bool width_valid = false;
  bool height_valid = false;

  while (!window.ShouldClose()) {

    width_box.CheckFocus();
    width_valid = width_box.HandleInput().value_or(false);
    height_box.CheckFocus();
    height_valid = height_box.HandleInput().value_or(false);

    if (width_box.CheckCollision(GetMousePosition()) ||
        height_box.CheckCollision(GetMousePosition())) {

      // sleep
      // std::this_thread::sleep_for(std::chrono::seconds(2));
      std::cout << "ibeam";
      // SetMouseCursor(MOUSE_CURSOR_IBEAM);
      // std::this_thread::sleep_for(std::chrono::seconds(2));
      // CRASHES

    } else {

      // SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    BeginDrawing();
    // window.ClearBackground();

    width_box.Draw();
    height_box.Draw();

    EndDrawing();
  }
  throw std::runtime_error("Window closed");
}
