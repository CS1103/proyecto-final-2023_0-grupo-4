#include "ViewMaze.hpp"
#include "Vector2I.hpp"
#include <algorithm>

ViewMaze::ViewCell::ViewCell(const SQUARE_TYPE &_type, const rl::Vector2 &_pos,
                             const rl::Vector2 &_size, rl::Texture &_texture)
    : type(_type), rect(_pos, _size), texture(_texture) {}

ViewMaze::ViewMaze(const maze_t &maze) : cells(maze.size()) {

  auto rows = maze.size();
  auto cols = maze[0].size();

  auto width = GetScreenWidth();
  auto height = GetScreenHeight();

  Utils::Vector2I size = {static_cast<int>(width / cols),
                          static_cast<int>(height / rows)};

  EmptyTexture().SetWidth(size.x);
  EmptyTexture().SetHeight(size.y);
  WallTexture().SetWidth(size.x);
  WallTexture().SetHeight(size.y);
  StartTexture().SetWidth(size.x);
  StartTexture().SetHeight(size.y);
  GoalTexture().SetWidth(size.x);
  GoalTexture().SetHeight(size.y);
  SearchedTexture().SetWidth(size.x);
  SearchedTexture().SetHeight(size.y);
  SolutionTexture().SetWidth(size.x);
  SolutionTexture().SetHeight(size.y);
  CurrentTexture().SetWidth(size.x);
  CurrentTexture().SetHeight(size.y);

  // ugly af, to improve with macros

  int cell_count = 0;

  auto position = [&](const int &_cell_count) {
    return Utils::Vector2I{static_cast<int>((_cell_count % cols) * size.x),
                           static_cast<int>((_cell_count / cols) * size.y)};
  };

  std::transform(maze.begin(), maze.end(), cells.begin(), [&](const auto &row) {
    std::vector<ViewCell> cells_v;
    cells_v.reserve(row.size());
    std::transform(
        row.begin(), row.end(), cells_v.begin(), [&](const SQUARE_TYPE &type) {
          switch (type) {
          case SQUARE_TYPE::WALL:
            return ViewCell(type, position(cell_count), size, WallTexture());
          case SQUARE_TYPE::EMPTY:
            return ViewCell(type, position(cell_count), size, EmptyTexture());
          case SQUARE_TYPE::START:
            return ViewCell(type, position(cell_count), size, StartTexture());
          case SQUARE_TYPE::GOAL:
            return ViewCell(type, position(cell_count), size, GoalTexture());
          case SQUARE_TYPE::SEARCHED:
            return ViewCell(type, position(cell_count), size,
                            SearchedTexture());
          case SQUARE_TYPE::SOLUTION:
            return ViewCell(type, position(cell_count), size,
                            SolutionTexture());
          case SQUARE_TYPE::CURRENT:
            throw std::runtime_error("Current cell can't be in empty maze");
          }
          throw std::runtime_error("Unknown cell type");
        });
    return cells_v;
  });
}

void ViewMaze::Draw() const {
  std::cout << "Drawing maze" << std::endl;
  for (const auto &row : cells) {

    for (const auto &cell : row) {
      if (cell.type == SQUARE_TYPE::WALL) {
        cell.rect.Draw(BLACK);
      } else {
        cell.rect.Draw(WHITE);
      }
    }
  }
}

void ViewMaze::DrawSearched(const square &current, const square &next) {
  auto [currX, currY] = current;
  auto [nextX, nextY] = next;

  cells[currY][currX].type = SQUARE_TYPE::SEARCHED;
  cells[currY][currX].texture = SearchedTexture();

  cells[nextY][nextX].type = SQUARE_TYPE::CURRENT;
  cells[nextY][nextX].texture = CurrentTexture();
}
void ViewMaze::DrawSolution(const square &current, const square &next) {
  auto [currX, currY] = current;
  auto [nextX, nextY] = next;

  cells[currY][currX].type = SQUARE_TYPE::SOLUTION;
  cells[currY][currX].texture = SolutionTexture();

  cells[nextY][nextX].type = SQUARE_TYPE::CURRENT;
  cells[nextY][nextX].texture = CurrentTexture();
}
