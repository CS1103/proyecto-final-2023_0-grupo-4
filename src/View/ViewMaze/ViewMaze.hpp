#ifndef VIEW_MAZE_HPP
#define VIEW_MAZE_HPP

#include "Maze.hpp"

#include <Rectangle.hpp>
#include <Texture.hpp>

#include "resources.hpp"

template <typename T> using matrix_t = std::vector<std::vector<T>>;

namespace rl = raylib;

constexpr std::string_view EMPTY_TEXTURE_PATH =
    RESOURCE_PATH "Textures/test_old_button.png";
constexpr std::string_view WALL_TEXTURE_PATH =
    RESOURCE_PATH "Textures/test_old_button.png";
constexpr std::string_view START_TEXTURE_PATH =
    RESOURCE_PATH "Textures/test_old_button.png";
constexpr std::string_view GOAL_TEXTURE_PATH =
    RESOURCE_PATH "Textures/test_old_button.png";

class ViewMaze {
public:
  explicit ViewMaze(const Maze &maze);
  void Draw() const {

    // board.Draw();

    // for (auto &row : cells) {
    //   for (auto &cell : row) {
    //     cell.texture.Draw(cell.rect);
    //   }
    // }
  }

  void MovePlayer(const square &current, const square &next) {

    // edit cells

    // cells[current].type = visited
    // cells[current].texture = SearchedTexture
    // cells[next].type = current
    // cells[next].texture = CurrentTexture // invalida
  }

private:
  const Maze &maze;

  struct ViewCell {

    SQUARE_TYPE type;
    rl::Rectangle rect;
    std::reference_wrapper<rl::Texture> texture;
    ViewCell(/*TODO*/);
  };

  rl::Rectangle board;
  matrix_t<ViewCell> cells;

  inline static raylib::Texture &EmptyTexture() {
    // TODO(luis enrique): Implement this
  }
  inline static raylib::Texture &WallTexture() {
    // TODO(luis enrique): Implement this
  }
  inline static raylib::Texture &StartTexture() {
    // TODO(luis enrique): Implement this
  }
  inline static raylib::Texture &GoalTexture() {
    // TODO(luis enrique): Implement this
  }
};

#endif // !VIEW_MAZE_HPP
