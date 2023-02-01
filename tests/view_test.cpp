#include <raylib-cpp.hpp>

namespace rl = raylib;

class View {
public:
  void run();
  inline static rl::Window s_window = rl::Window(1, 2, "a");

private:
};

class Button {

public:
  void Draw(const int &pos_x, const int &pos_y) {
    s_texture.Draw(pos_x, pos_y);
  }

private:
  inline static rl::Texture s_texture =
      rl::Texture("../src/assets/Textures/test_old_button.png");
};

void View::run() {

  Button but;
  Button but2;

  auto c = 0;
  while (!s_window.ShouldClose()) {

    BeginDrawing();

    but.Draw(100, 100);
    but2.Draw(300, 300);

    c++;
    if (c == 3000) {
      break;
    }
    EndDrawing();
  }
}
int main() {

  View view;

  view.run();

  return 0;
}
