#ifndef VIEW_MAZE_HPP
#define VIEW_MAZE_HPP

#include "Maze.hpp"

#include <Rectangle.hpp>
#include <Texture.hpp>
#include <functional>

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

// Temporal

constexpr std::string_view SEARCHED_TEXTURE_PATH =
    RESOURCE_PATH "Textures/empty_tile_v2.png";
constexpr std::string_view SOLUTION_TEXTURE_PATH =
    RESOURCE_PATH "Textures/empty_tile_v3.png";
constexpr std::string_view CURRENT_TEXTURE_PATH =
    RESOURCE_PATH "Textures/empty_tile_v3.png";

class ViewMaze {
public:
  explicit ViewMaze(const maze_t &maze);

  void Draw() const;

  void DrawSearched(const square &current, const square &next);
  void DrawSolution(const square &current, const square &next);

  square MoveRight();
  square MoveLeft();
  square MoveDown();
  square MoveUp();

  void Clear();

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

  inline static rl::Texture &EmptyTexture() {
    static rl::Texture s_empty_texture(EMPTY_TEXTURE_PATH.data());
    return s_empty_texture;
  }
  inline static raylib::Texture &WallTexture() {
    static rl::Texture s_wall_texture(WALL_TEXTURE_PATH.data());
    return s_wall_texture;
  }
  inline static raylib::Texture &StartTexture() {
    static rl::Texture s_start_texture(START_TEXTURE_PATH.data());
    return s_start_texture;
  }
  inline static raylib::Texture &GoalTexture() {
    static rl::Texture s_goal_texture(GOAL_TEXTURE_PATH.data());
    return s_goal_texture;
  }
  inline static raylib::Texture &SearchedTexture() {
    static rl::Texture s_searched_texture(SEARCHED_TEXTURE_PATH.data());
    return s_searched_texture;
  }
  inline static raylib::Texture &SolutionTexture() {
    static rl::Texture s_solution_texture(SOLUTION_TEXTURE_PATH.data());
    return s_solution_texture;
  }
  inline static raylib::Texture &CurrentTexture() {
    static rl::Texture s_current_texture(CURRENT_TEXTURE_PATH.data());
    return s_current_texture;
  }
};

#endif // !VIEW_MAZE_HPP
