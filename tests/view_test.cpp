#include <raylib-cpp.hpp>

constexpr std::string_view WINDOW_TITLE = "GAME_NAME";
constexpr int VIEW_WIDTH = 800;
constexpr int VIEW_HEIGHT = 600;

namespace rl = raylib;

class View {
public:
  void run();

private:
  static rl::Window &sWindow(const int &width = VIEW_WIDTH,
                             const int &height = VIEW_HEIGHT,
                             const std::string &name = WINDOW_TITLE.data()) {
    static rl::Window m_window = rl::Window(width, height, name);
    return m_window;
  }
  rl::Window &m_window = sWindow();
};

class Button {

public:
  void Draw(const int &pos_x, const int &pos_y) {
    sTexture().Draw(pos_x, pos_y);
  }

private:
  inline static rl::Texture &sTexture() {
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
