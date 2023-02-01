#include <iostream>
#include <memory>
#include <raylib-cpp.hpp>
// #include <raylib.h>

namespace rl = raylib;
// constexpr std::string_view DEFAULT_TEXTURE_PATH =
//     "../src/assets/Textures/test_old_button.png";
// const std::string DEFAULT_TEXTURE_PATH =
//     "../src/assets/Textures/test_old_button.png";

// class TextureWrapper {
// public:
//   static rl::Texture &instance() {
//     static rl::Texture instance(DEFAULT_TEXTURE_PATH.data());
//     return instance;
//   }
//   TextureWrapper() = delete;
// };

// class Button { // NOLINT
// public:
//   Button() = default;

//   // if (!shared_texture) {
//   //   shared_texture =
//   //       std::make_unique<rl::Texture>(DEFAULT_TEXTURE_PATH.data());
//   // }
//   // }

//   void Draw(const int &posX, const int &posY) const {
//     // shared_texture->Draw(posX, posY);
//     TextureWrapper::instance().Draw(posX, posY);
//   }

// private:
//   // inline static std::unique_ptr<rl::Texture> shared_texture = nullptr;
//   // [[clang::no_destroy]] inline static std::unique_ptr<rl::Texture>
//   //     shared_texture = nullptr;

//   // [[nodiscard]] static const rl::Texture &texture() { return
//   *shared_texture;
//   // }
// };

int main() {

  rl::Window window(800, 600, "Hello World");
  const std::string path = "../src/assets/Textures/test_old_button.png";
  rl::Texture text_1(path);
  // Button but;

  auto counter = 500;

  while (!window.ShouldClose()) {
    BeginDrawing();

    // but.Draw(100, 100);
    text_1.Draw(100, 100);

    std::cout << "Counter: " << counter << std::endl;
    if (--counter <= 0) {
      break;
    }

    EndDrawing();
  }

  return 0;
}
