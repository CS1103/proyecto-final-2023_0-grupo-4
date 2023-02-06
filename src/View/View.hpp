#ifndef VIEW_H
#define VIEW_H

#include "../Config/Config.hpp"
#include <iostream>
#include <raylib-cpp.hpp>

namespace rl = raylib;

constexpr std::string_view WINDOW_TITLE = "GAME_NAME";
constexpr int VIEW_WIDTH = 800;
constexpr int VIEW_HEIGHT = 600;

constexpr std::string_view BACKGROUND_TEXTURE =
    "../src/assets/Textures/floor_tile_v2.jpg";

class View {
public:
  void StartScreen();
  Config GetConfig();

private:
  static rl::Window &GetWindow(const int &width = VIEW_WIDTH,
                               const int &height = VIEW_HEIGHT,
                               const std::string &name = WINDOW_TITLE.data()) {
    static rl::Window s_window = rl::Window(width, height, name); // NOLINT
    return s_window;
  }
  static rl::Texture &GetBackground() {
    static rl::Texture s_background = rl::Texture(BACKGROUND_TEXTURE.data());
    return s_background;
  }

  rl::Window &window = GetWindow();
  rl::Texture &background = GetBackground();
};

#endif // !VIEW_H
