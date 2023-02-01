#include <raylib-cpp.hpp>

namespace rl = raylib;
class View {
public:
  void run();
  // inline static rl::Window s_window = rl::Window(1, 2, "a");
  static rl::Window &sWindow() {
    static rl::Window s_window(500, 700, "name");
    return s_window;
  }

private:
};

class Button {

public:
  void Draw(const int &pos_x, const int &pos_y) {
    sTexture().Draw(pos_x, pos_y);
  }

private:
  static rl::Texture &sTexture() {
    static rl::Texture s_texture("../src/assets/Textures/test_old_button.png");
    return s_texture;
  }
};

void View::run() {

  Button but;
  Button but2;

  auto count = 0;
  while (!sWindow().ShouldClose()) {

    BeginDrawing();

    but.Draw(100, 100);
    but2.Draw(300, 300);

    count++;
    if (count == 3000) {
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
