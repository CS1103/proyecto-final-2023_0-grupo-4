#include <raylib-cpp.hpp>

namespace rl = raylib;

int main() {

  rl::Window win(500, 500, "name");

  while (!win.ShouldClose()) {

    // if (IsMouseButtonPressed(0)) {

    auto pos = GetTouchPosition(0);
    std::cout << "touch\n";
    std::cout << pos.x << "  " << pos.y << '\n';
    auto pos2 = GetMousePosition();
    std::cout << "mouse\n";
    std::cout << pos2.x << "  " << pos2.y << '\n';
    // }
    // if (IsMouseButtonDown(0)) {

    //   auto pos = GetTouchPosition(0);
    //   std::cout << "but down\n";
    //   std::cout << pos.x << "  " << pos.y << '\n';
    // }

    BeginDrawing();

    EndDrawing();
  }

  return 0;
}
