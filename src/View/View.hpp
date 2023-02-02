#ifndef VIEW_H
#define VIEW_H

#include <raylib-cpp.hpp>

namespace rl = raylib;

constexpr std::string_view WINDOW_TITLE = "GAME_NAME";
constexpr int VIEW_WIDTH = 800;
constexpr int VIEW_HEIGHT = 600;

class View {
public:
  void startScreen();

private:
  static rl::Window &getWindow(const int &width = VIEW_WIDTH,
                               const int &height = VIEW_HEIGHT,
                               const std::string &name = WINDOW_TITLE.data()) {
    static rl::Window s_window = rl::Window(width, height, name); // NOLINT
    return s_window;
  }

  rl::Window &window = getWindow();
};

#endif // !VIEW_H
