#ifndef VIEW_MAZE_HPP
#define VIEW_MAZE_HPP

#include "Maze.hpp"
#include <raylib.h>

constexpr std::string_view EMPTY_TEXTURE_PATH =
    "../src/assets/Textures/test_old_button.png";
constexpr std::string_view WALL_TEXTURE_PATH =
    "../src/assets/Textures/test_old_button.png";
constexpr std::string_view START_TEXTURE_PATH =
    "../src/assets/Textures/test_old_button.png";
constexpr std::string_view GOAL_TEXTURE_PATH =
    "../src/assets/Textures/test_old_button.png";

class ViewMaze {
public:
  explicit ViewMaze(Maze &maze);

private:
  Maze &maze;
};

#endif // !VIEW_MAZE_HPP
