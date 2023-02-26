#include "ViewMaze.hpp"
#include <algorithm>

ViewMaze::ViewCell::ViewCell(const SQUARE_TYPE &_type, const rl::Vector2 &_pos,
                             const rl::Vector2 &_size, rl::Texture &_texture)
    : type(_type), rect(_pos, _size), texture(_texture) {}

ViewMaze::ViewMaze(const maze_t &maze) {

  auto [rows, cols] = std::make_pair(maze.size(), maze[0].size());
  cells.reserve(rows);

  std::transform(maze.begin(), maze.end(), cells.begin(), [](const auto &row) {
    std::vector<ViewCell> cells_v;
    cells_v.reserve(row.size());
    std::transform(row.begin(), row.end(), cells_v.begin(),
                   [](const SQUARE_TYPE &type) {
                     switch (type) {
                     case SQUARE_TYPE::WALL:
                       return ViewCell(type, rl::Vector2(0, 0),
                                       rl::Vector2(0, 0), WallTexture());
                     case SQUARE_TYPE::EMPTY:
                       return ViewCell(type, rl::Vector2(0, 0),
                                       rl::Vector2(0, 0), EmptyTexture());
                     case SQUARE_TYPE::START:
                       return ViewCell(type, rl::Vector2(0, 0),
                                       rl::Vector2(0, 0), StartTexture());
                     case SQUARE_TYPE::GOAL:
                       return ViewCell(type, rl::Vector2(0, 0),
                                       rl::Vector2(0, 0), GoalTexture());
                     case SQUARE_TYPE::SEARCHED:
                       return ViewCell(type, rl::Vector2(0, 0),
                                       rl::Vector2(0, 0), SearchedTexture());
                     case SQUARE_TYPE::SOLUTION:
                       return ViewCell(type, rl::Vector2(0, 0),
                                       rl::Vector2(0, 0), SolutionTexture());
                     }
                   });
    return cells_v;
  });
}
