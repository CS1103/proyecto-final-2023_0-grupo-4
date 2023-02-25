#ifndef VIEW_H
#define VIEW_H

#include "Bot.hpp"
#include "Config.hpp"
#include "ViewMaze.hpp"

#include "Maze.hpp"
#include <iostream>

#include <Texture.hpp>
#include <Window.hpp>

#include "resources.hpp"

using MazeSteps = std::queue<square>;

namespace rl = raylib;

constexpr int WINDOW_FPS = 30;

constexpr std::string_view WINDOW_TITLE = "GAME_NAME";
constexpr int VIEW_WIDTH = 800;
constexpr int VIEW_HEIGHT = 600;

constexpr std::string_view BACKGROUND_TEXTURE =
    RESOURCE_PATH "Textures/background.png";

class View {
public:
  void StartScreen();
  Config GetConfig();

  void LoadMaze(const maze_t &maze);

  std::pair<ALGORITHM, bool> BotMode(std::optional<MazeSteps> solution,
                                     std::optional<MazeSteps> searched);

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

    auto [width, height] = GetWindow().GetSize();

    s_background.SetWidth(static_cast<int>(width));
    s_background.SetHeight(static_cast<int>(height));

    return s_background;
  }

  rl::Window &window = GetWindow();
  rl::Texture &background = GetBackground();
  std::optional<ViewMaze> view_maze = std::nullopt; // For lazy initialization
};

#endif // !VIEW_H
