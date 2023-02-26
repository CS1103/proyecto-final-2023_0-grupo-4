#ifndef VIEW_MAZE_HPP
#define VIEW_MAZE_HPP

#include "Maze.hpp"

#include <Rectangle.hpp>
#include <Texture.hpp>

#include "resources.hpp"

template <typename T> using matrix_t = std::vector<std::vector<T>>;

namespace rl = raylib;

constexpr std::string_view EMPTY_TEXTURE_PATH =
    RESOURCE_PATH "Textures/empty_tile_v1.png";
constexpr std::string_view WALL_TEXTURE_PATH =
    RESOURCE_PATH "Textures/wall.png";
constexpr std::string_view START_TEXTURE_PATH =
    RESOURCE_PATH "Textures/start_tile.png";
constexpr std::string_view GOAL_TEXTURE_PATH =
    RESOURCE_PATH "Textures/goal_tile_v1.png";
constexpr std::string_view SEARCHED_TEXTURE_PATH =
    RESOURCE_PATH "Textures/searched_tile.png";
constexpr std::string_view SOLUTION_TEXTURE_PATH =
    RESOURCE_PATH "Textures/solution_tile_v1.png";

class ViewMaze {
public:
  explicit ViewMaze(const maze_t &maze); // construct directly from matrix
  void Draw() const;                     // {

  void DrawSearched(const square &current, const square &next);
  void DrawSolution(const square &current, const square &next);

private:
  struct ViewCell {

    SQUARE_TYPE type;
    rl::Rectangle rect;
    std::reference_wrapper<rl::Texture> texture;

    ViewCell() = delete;

    ViewCell(const SQUARE_TYPE &_type, const rl::Vector2 &_pos,
             const rl::Vector2 &_size, rl::Texture &_texture);
  };

  rl::Rectangle board;
  matrix_t<ViewCell> cells;

  const rl::Texture &EMPTY_TEXTURE = EmptyTexture();
  const rl::Texture &WALL_TEXTURE = WallTexture();
  const rl::Texture &START_TEXTURE = StartTexture();
  const rl::Texture &GOAL_TEXTURE = GoalTexture();
  const rl::Texture &SEARCHED_TEXTURE = SearchedTexture();
  const rl::Texture &SOLUTION_TEXTURE = SolutionTexture();

  inline static rl::Texture &EmptyTexture() {
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
  inline static raylib::Texture &SearchedTexture() {
    // TODO(luis enrique): Implement this
  }
  inline static raylib::Texture &SolutionTexture() {
    // TODO(luis enrique): Implement this
  }
};

#endif // !VIEW_MAZE_HPP
