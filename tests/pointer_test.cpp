#include <iostream>
#include <memory>
#include <raylib-cpp.hpp>

namespace rl = raylib;
constexpr std::string_view DEFAULT_TEXTURE_PATH =
    "../src/assets/Textures/test_old_button.png";

class Button { // NOLINT
public:
  Button() {

    if (shared_texture == nullptr) {
      // store shared_texture in heap
      // shared_texture =
      shared_texture = new rl::Texture(DEFAULT_TEXTURE_PATH.data());
    }
  }

  void Draw(const int &posX, const int &posY) const {
    shared_texture->Draw(posX, posY);
  }

private:
  // std::shared_ptr<rl::Texture> shared_texture (new )
  // store shared texture in heap
  // std::shared_ptr<rl::Texture> shared_texture =
  //     std::make_shared<rl::Texture>(DEFAULT_TEXTURE_PATH.data());

  // [[nodiscard]] const rl::Texture &texture() { return *shared_texture; }
  rl::Texture *shared_texture;
};

int main() {

  rl::Window window(800, 600, "Hello World");
  Button but;
  Button but2;
  Button but3;

  auto counter = 500;

  while (!window.ShouldClose()) {
    BeginDrawing();

    but.Draw(100, 100);
    but2.Draw(200, 200);
    but3.Draw(400, 400);

    std::cout << "Counter: " << counter << std::endl;
    if (--counter <= 0) {
      break;
    }

    EndDrawing();
  }

  return 0;
}
