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
