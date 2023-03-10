#include "ViewMaze.hpp"
#include "Vector2I.hpp"
#include <algorithm>
#include <iostream>
ViewMaze::ViewCell::ViewCell(const SQUARE_TYPE &_type, const rl::Vector2 &_pos,
                             rl::Texture &_texture)
    : type(_type), position(_pos), texture(_texture) {}

ViewMaze::ViewMaze(const maze_t &maze, const bool &fullScreen)
    : cells(maze.size()) {

  auto rows = maze.size();
  auto cols = maze[0].size();

  auto width = GetScreenWidth();
  auto height = GetScreenHeight();

  if (!fullScreen) {
    width = width * 0.7;
    height = height * 0.7;
  }

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
  CurrentBotTexture().SetWidth(size.x);
  CurrentBotTexture().SetHeight(size.y);
  CurrentPlayerTexture().SetWidth(size.x);
  CurrentPlayerTexture().SetHeight(size.y);
  // ugly af, to improve with macros

  int cell_count = -1;

  auto position = [&](const int &_cell_count) {
    return Utils::Vector2I{static_cast<int>((_cell_count % cols) * size.x),
                           static_cast<int>((_cell_count / cols) * size.y)};
  };

  std::transform(maze.begin(), maze.end(), cells.begin(), [&](const auto &row) {
    std::vector<ViewCell> cells_v;
    cells_v.reserve(row.size());
    std::transform(
        row.begin(), row.end(), std::back_inserter(cells_v),
        [&](const SQUARE_TYPE &type) {
          cell_count++;
          switch (type) {
          case SQUARE_TYPE::WALL:
            return ViewCell(type, position(cell_count), WallTexture());
          case SQUARE_TYPE::EMPTY:
            return ViewCell(type, position(cell_count), EmptyTexture());
          case SQUARE_TYPE::START:
            return ViewCell(type, position(cell_count), StartTexture());
          case SQUARE_TYPE::GOAL:
            return ViewCell(type, position(cell_count), GoalTexture());
          case SQUARE_TYPE::SEARCHED:
            return ViewCell(type, position(cell_count), SearchedTexture());
          case SQUARE_TYPE::SOLUTION:
            return ViewCell(type, position(cell_count), SolutionTexture());
          case SQUARE_TYPE::CURRENT:
            throw std::runtime_error("Current cell can't be in empty maze");
          }
          throw std::runtime_error("Unknown cell type");
        });
    return cells_v;
  });
}

void ViewMaze::Draw() const {

  for (const auto &row : cells) {
    for (const auto &cell : row) {
      cell.texture.get().Draw(cell.position);
    }
  }
}

void ViewMaze::DrawSearched(const square &current, const square &next) {

  auto [currX, currY] = current;
  auto [nextX, nextY] = next;

  ViewCell &searched_cell = cells[currX][currY];
  if (searched_cell.type == SQUARE_TYPE::CURRENT) {
    searched_cell.type = SQUARE_TYPE::SEARCHED;
    searched_cell.texture = SearchedTexture();
  }

  ViewCell &current_cell = cells[nextX][nextY];

  if (current_cell.type == SQUARE_TYPE::EMPTY) {
    current_cell.type = SQUARE_TYPE::CURRENT;
    current_cell.texture = CurrentBotTexture();
  }
}
void ViewMaze::DrawSolution(const square &current, const square &next) {

  auto [currX, currY] = current;
  auto [nextX, nextY] = next;

  ViewCell &searched_cell = cells[currX][currY];

  if (searched_cell.type == SQUARE_TYPE::CURRENT) {

    cells[currX][currY].type = SQUARE_TYPE::SOLUTION;
    cells[currX][currY].texture = SolutionTexture();
  }

  ViewCell &current_cell = cells[nextX][nextY];

  if (current_cell.type == SQUARE_TYPE::SEARCHED) {
    cells[nextX][nextY].type = SQUARE_TYPE::CURRENT;
    cells[nextX][nextY].texture = CurrentBotTexture();
  }
}
void ViewMaze::MoveRight(square &current) {

  auto [currX, currY] = current;

  ViewCell &next = cells[currX][currY + 1];

  if (currY + 1 >= cells[0].size() || next.type == SQUARE_TYPE::WALL) {
    return;
  }

  ViewCell &current_cell = cells[currX][currY];

  if (current_cell.type == SQUARE_TYPE::CURRENT) {
    current_cell.texture = SearchedTexture();
    current_cell.type = SQUARE_TYPE::SEARCHED;
  }
  if (next.type == SQUARE_TYPE::EMPTY || next.type == SQUARE_TYPE::SEARCHED) {
    next.type = SQUARE_TYPE::CURRENT;
    next.texture = CurrentPlayerTexture();
  }
  current = {currX, currY + 1};
}

void ViewMaze::MoveLeft(square &current) {

  auto [currX, currY] = current;

  ViewCell &next = cells[currX][currY - 1];

  if (currY < 1 || next.type == SQUARE_TYPE::WALL) {
    return;
  }
  ViewCell &current_cell = cells[currX][currY];
  if (current_cell.type == SQUARE_TYPE::CURRENT) {
    current_cell.texture = SearchedTexture();
    current_cell.type = SQUARE_TYPE::SEARCHED;
  }
  if (next.type == SQUARE_TYPE::EMPTY || next.type == SQUARE_TYPE::SEARCHED) {
    next.type = SQUARE_TYPE::CURRENT;
    next.texture = CurrentPlayerTexture();
  }
  current = {currX, currY - 1};
}
void ViewMaze::MoveDown(square &current) {

  auto [currX, currY] = current;

  ViewCell &next = cells[currX + 1][currY];

  if (currX + 1 >= cells.size() || next.type == SQUARE_TYPE::WALL) {
    return;
  }
  ViewCell &current_cell = cells[currX][currY];
  if (current_cell.type == SQUARE_TYPE::CURRENT) {
    current_cell.texture = SearchedTexture();
    current_cell.type = SQUARE_TYPE::SEARCHED;
  }
  if (next.type == SQUARE_TYPE::EMPTY || next.type == SQUARE_TYPE::SEARCHED) {
    next.type = SQUARE_TYPE::CURRENT;
    next.texture = CurrentPlayerTexture();
  }
  current = {currX + 1, currY};
}
void ViewMaze::MoveUp(square &current) {
  auto [currX, currY] = current;
  ViewCell &next = cells[currX - 1][currY];
  if (currX < 1 || next.type == SQUARE_TYPE::WALL) {
    return;
  }
  ViewCell &current_cell = cells[currX][currY];
  if (current_cell.type == SQUARE_TYPE::CURRENT) {
    current_cell.texture = SearchedTexture();
    current_cell.type = SQUARE_TYPE::SEARCHED;
  }
  if (next.type == SQUARE_TYPE::EMPTY || next.type == SQUARE_TYPE::SEARCHED) {
    next.type = SQUARE_TYPE::CURRENT;
    next.texture = CurrentPlayerTexture();
  }
  current = {currX - 1, currY};
}

void ViewMaze::Clear() {

  // change all searched an solution cells to empty
  std::for_each(cells.begin(), cells.end(), [&](auto &row) {
    std::for_each(row.begin(), row.end(), [&](auto &cell) {
      if (cell.type == SQUARE_TYPE::SEARCHED ||
          cell.type == SQUARE_TYPE::SOLUTION ||
          cell.type == SQUARE_TYPE::CURRENT) {
        cell.type = SQUARE_TYPE::EMPTY;
        cell.texture = EmptyTexture();
      }
    });
  });
}
