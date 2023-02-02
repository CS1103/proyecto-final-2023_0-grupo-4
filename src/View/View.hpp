#ifndef VIEW_H
#define VIEW_H

#include <initializer_list>
#include <raylib-cpp.hpp>

namespace rl = raylib;

constexpr std::string_view WINDOW_TITLE = "GAME_NAME";
constexpr int VIEW_WIDTH = 800;
constexpr int VIEW_HEIGHT = 600;

class View {
public:
private:
  static rl::Window &s_window;
  static rl::Window &getWindow(const std::string &title = WINDOW_TITLE.data(),
                               const int &width = VIEW_HEIGHT,
                               const int &height = VIEW_HEIGHT) {
    static rl::Window s_window(width, height, title);
    return s_window;
  }
  void startScreen();
};
#endif // !VIEW_H
