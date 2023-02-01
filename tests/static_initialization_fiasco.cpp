#include <iostream>
#include <memory>
#include <raylib-cpp.hpp>

namespace rl = raylib;
constexpr std::string_view DEFAULT_TEXTURE_PATH =
    "../src/assets/Textures/test_old_button.png";

class View {
  inline static rl::Window window{};
};

class Button {
public:
  Button() = default;

  void Draw(const int &posX, const int &posY) const {
    shared_texture.Draw(posX, posY);
  }

private:
  inline static rl::Texture shared_texture =
      rl::Texture(DEFAULT_TEXTURE_PATH.data());
};

int main() {

  Button but;

  auto counter = 500;

  while (!window.ShouldClose()) {
    BeginDrawing();

    text.Draw(100, 100);

    std::cout << "Counter: " << counter << std::endl;
    if (--counter <= 0) {
      break;
    }

    EndDrawing();
  }

  return 0;
}
