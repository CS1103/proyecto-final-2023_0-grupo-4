#ifndef VIEW_H
#define VIEW_H

#include "../Config/Config.hpp"
#include "Maze.hpp"
#include <iostream>
#include <raylib-cpp.hpp>

#include "resources.hpp"

constexpr int WINDOW_FPS = 30;

namespace rl = raylib;

constexpr std::string_view WINDOW_TITLE = "GAME_NAME";
constexpr int VIEW_WIDTH = 800;
constexpr int VIEW_HEIGHT = 600;

constexpr std::string_view BACKGROUND_TEXTURE =
    RESOURCE_PATH "Textures/test_old_button.png";

template <typename T>
concept Drawable = requires(T obj) {
                     { obj.Draw() } -> std::same_as<void>;
                   };

class View {
public:
  void StartScreen();
  Config GetConfig();
  void PrintPath(const Maze &maze,
                 const std::unordered_set<square, Maze::HashPair> &path);

private:
  static rl::Window &GetWindow(const int &width = VIEW_WIDTH,
                               const int &height = VIEW_HEIGHT,
                               const std::string &name = WINDOW_TITLE.data()) {
    static rl::Window s_window = rl::Window(width, height, name); // NOLINT
    s_window.SetTargetFPS(WINDOW_FPS);
    return s_window;
  }
  static rl::Texture &GetBackground() {
    static rl::Texture s_background = rl::Texture(BACKGROUND_TEXTURE.data());
    return s_background;
  }

  rl::Window &window = GetWindow();
  rl::Texture &background = GetBackground();

  template <typename... Args>
    requires(Drawable<Args> && ...)
  inline void DrawAll(Args &&...args) {
    (args.Draw(), ...);
  }
};

#endif // !VIEW_H
