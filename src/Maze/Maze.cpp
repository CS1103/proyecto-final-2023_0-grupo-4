#include "Maze.hpp"
#include <algorithm>
#include <random>

#include "../Utils/Utils.h"

// Testing
#include <cstdint>
#include <iostream>
#include <sys/types.h>

constexpr uint8_t MAX_WIDTH = 21;
constexpr uint8_t MIN_WIDTH = 10;
constexpr uint8_t MAX_HEIGHT = 15;
constexpr uint8_t MIN_HEIGHT = 7;

Maze::Maze(uint8_t customHeight, uint8_t customWidth)
    : base_height(customHeight), base_width(customWidth) {
  uint8_t height = base_height * 2 + 1;
  uint8_t width = base_width * 2 + 1;

  generateMaze(height, width);
}
Maze::Maze()
    : base_height(Utils::RandomNum<uint8_t>(MIN_HEIGHT, MAX_HEIGHT)),
      base_width(Utils::RandomNum<uint8_t>(MIN_WIDTH, MAX_WIDTH)) {

  uint8_t height = base_height * 2 + 1;
  uint8_t width = base_width * 2 + 1;

  generateMaze(height, width);
}

// Methods to hunt next square
template <>
std::optional<square> Maze::hunt<HUNT_METHOD::RANDOM>(const uint8_t &count);
template <>
std::optional<square> Maze::hunt<HUNT_METHOD::SERPENTINE>(const uint8_t &count);

void Maze::generateMaze(uint8_t height, uint8_t width) {
  // Allocate memory for the board
  m_maze.resize(height);
  for (auto &row : m_maze) {
    for (auto i = 0; i < width; i++) {
      row.emplace_back(SQUARE_TYPE::WALL);
    }
  }

  uint8_t start_x = 0;
  uint8_t start_y = 0;

  do {
    start_x = Utils::RandomNum<uint8_t>(1, height - 1);
  } while (start_x % 2 != 1);
  do {
    start_y = Utils::RandomNum<uint8_t>(1, width - 1);
  } while (start_y % 2 != 1);

  m_maze[start_x][start_y] = SQUARE_TYPE::EMPTY;

  uint8_t visit_count = 1;

  auto first_hunt_opt = hunt(visit_count);

  // while (first_hunt_opt.has_value()) {
  //   auto [row, col] = first_hunt_opt.value();
  //   auto walk = randomWalk({row, col});

  //   visit_count = solveRandomWalk(walk, {row, col});
  //   first_hunt_opt = hunt(visit_count);
  //   // printMaze();
  // }

  // Not a good solution but works ig
  for (auto i = 0; i < pow(base_width, 3); i++) {
    auto [row, col] = first_hunt_opt.value();
    auto walk = randomWalk({row, col});

    visit_count = solveRandomWalk(walk, {row, col});
    first_hunt_opt = hunt(visit_count);
  }

  do {
    start_x = Utils::RandomNum<uint8_t>(1, height - 1);
    start_y = Utils::RandomNum<uint8_t>(1, width - 1);
  } while (m_maze[start_x][start_y] != SQUARE_TYPE::EMPTY);
  m_maze[start_x][start_y] = SQUARE_TYPE::START;
  m_start = {start_x, start_y};

  uint8_t end_x = 0;
  uint8_t end_y = 0;
  // END
  do {
    end_x = Utils::RandomNum<uint8_t>(1, height - 1);
    end_y = Utils::RandomNum<uint8_t>(1, width - 1);
  } while (m_maze[end_x][end_y] != SQUARE_TYPE::EMPTY);
  m_maze[end_x][end_y] = SQUARE_TYPE::END;
  m_goal = {end_x, end_y};
}

void Maze::printMaze() {
  std::cout << "Maze:" << std::endl;

  for (auto &row : m_maze) {
    for (auto &elem : row) {
      std::cout << elem;
    }
    std::cout << std::endl;
  }
}

template <>
std::optional<square> Maze::hunt<HUNT_METHOD::RANDOM>(const uint8_t &count) {
  // CHECKED

  if (count >= base_height * base_width) {
    // std::cout << "All squares visited" << std::endl;
    return std::nullopt;
  }

  uint8_t row = 0;
  uint8_t col = 0;

  do {
    row = Utils::RandomNum<uint8_t>(1, static_cast<uint8_t>(m_maze.size() - 1));
  } while (row % 2 != 1);

  do {
    col = Utils::RandomNum<uint8_t>(1,
                                    static_cast<uint8_t>(m_maze[0].size() - 1));
  } while (col % 2 != 1);

  // std::cout << "Hunting at: " << static_cast<int>(row) << ", "
  //           << static_cast<int>(col) << std::endl;

  // printMaze();

  return std::make_pair(row, col);
}

template <>
std::optional<square>
Maze::hunt<HUNT_METHOD::SERPENTINE>(const uint8_t & /*count*/) {
  // TODO(enrique): Implement serpentine
  throw std::runtime_error("Not implemented");
}

template <class T1, class T2>
size_t Maze::HashPair::operator()(const std::pair<T1, T2> &pair) const {
  // https://www.geeksforgeeks.org/how-to-create-an-unordered_map-of-pairs-in-c/
  auto hash1 = std::hash<T1>{}(pair.first);
  auto hash2 = std::hash<T2>{}(pair.second);

  if (hash1 != hash2) {
    return hash1 ^ hash2;
  }

  // If hash1 == hash2, their XOR is zero.
  return hash1;
}

std::unordered_map<square, direction_t, Maze::HashPair>
Maze::randomWalk(const square &start) {
  // ERROR HERE??

  direction_t direction = randomDirection(start);
  std::unordered_map<square, direction_t, Maze::HashPair> walk;
  walk[start] = direction;

  auto current = move(start, direction);

  while (m_maze[current.first][current.second] == SQUARE_TYPE::WALL) {
    direction = randomDirection(current);
    walk[current] = direction;
    current = move(current, direction);
  }
  return walk;
}

direction_t Maze::randomDirection(const square &current) {
  // CHECKED

  auto [row, col] = current;

  std::vector<direction_t> directions;

  if (row > 1) {
    directions.emplace_back(DIRECTION::NORTH);
  }
  if (row < m_maze.size() - 2) {
    directions.emplace_back(DIRECTION::SOUTH);
  }
  if (col > 1) {
    directions.emplace_back(DIRECTION::EAST);
  }
  if (col < m_maze[0].size() - 2) {
    directions.emplace_back(DIRECTION::WEST);
  }

  return directions[Utils::RandomNum<size_t>(0, directions.size() - 1)];
}

square Maze::move(const square &current, const direction_t &direction) {
  return {current.first + direction.first, current.second + direction.second};
}

uint8_t Maze::solveRandomWalk(
    const std::unordered_map<square, direction_t, HashPair> &walk,
    const square &start) {

  uint8_t count = 0;

  square current = start;
  // std::cout << "Start: (" << static_cast<int>(current.first) << ", "
  //           << static_cast<int>(current.second) << ")" << std::endl;
  // std::cout << "value: "
  //           << static_cast<int>(m_maze[current.first][current.second])
  //           << std::endl
  //           << std::endl;
  // printMaze();

  // std::cout << m_maze[current.first][current.second];
  while (m_maze[current.first][current.second] != SQUARE_TYPE::EMPTY) {
    m_maze[current.first][current.second] = SQUARE_TYPE::EMPTY;
    square next = move(current, walk.at(current));
    uint8_t new_x = (next.first + current.first) / 2;
    uint8_t new_y = (next.second + current.second) / 2;
    m_maze[new_x][new_y] = SQUARE_TYPE::EMPTY;
    count++;
    current = next;
  }
  return count;
}

maze_t Maze::getMaze() const { return m_maze; }
square Maze::getStart() const { return m_start; }
square Maze::getEnd() const { return m_goal; }

std::vector<square> Maze::getNeighbors(const square &current) const {

  auto [row, col] = current;

  std::vector<square> neighbors;

  if (row > 0 && m_maze[row - 1][col] != SQUARE_TYPE::WALL) {
    neighbors.emplace_back(row - 1, col);
  }
  if (row < m_maze.size() - 1 && m_maze[row + 1][col] != SQUARE_TYPE::WALL) {
    neighbors.emplace_back(row + 1, col);
  }
  if (col > 0 && m_maze[row][col - 1] != SQUARE_TYPE::WALL) {
    neighbors.emplace_back(row, col - 1);
  }
  if (col < m_maze[0].size() - 1 && m_maze[row][col + 1] != SQUARE_TYPE::WALL) {
    neighbors.emplace_back(row, col + 1);
  }

  return neighbors;
}

void Maze::paintPath(const std::vector<square> &path) {
  for (const auto &sqr : path) {
    if (m_maze[sqr.first][sqr.second] != SQUARE_TYPE::START &&
        m_maze[sqr.first][sqr.second] != SQUARE_TYPE::END) {
      m_maze[sqr.first][sqr.second] = SQUARE_TYPE::PATH;
    }
  }
}
void Maze::paintPath(const std::vector<square> &solution,
                     const std::vector<square> &searchedPath) {
  for (const auto &sqr : solution) {
    if (m_maze[sqr.first][sqr.second] != SQUARE_TYPE::START &&
        m_maze[sqr.first][sqr.second] != SQUARE_TYPE::END) {
      m_maze[sqr.first][sqr.second] = SQUARE_TYPE::PATH;
    }
  }
  for (const auto &sqr : searchedPath) {
    if (m_maze[sqr.first][sqr.second] != SQUARE_TYPE::START &&
        m_maze[sqr.first][sqr.second] != SQUARE_TYPE::END &&
        m_maze[sqr.first][sqr.second] != SQUARE_TYPE::PATH) {
      m_maze[sqr.first][sqr.second] = SQUARE_TYPE::SEARCHED;
    }
  }
}

std::ostream &operator<<(std::ostream &ost, const SQUARE_TYPE &type) {
  switch (type) {
  case SQUARE_TYPE::WALL:
    ost << "██";
    break;
  case SQUARE_TYPE::EMPTY:
    ost << "  ";
    break;
  case SQUARE_TYPE::START:
    ost << "";
    break;
  case SQUARE_TYPE::END:
    ost << " ";
    break;
  case SQUARE_TYPE::PATH:
    ost << " ";
    break;
  case SQUARE_TYPE::SEARCHED:
    ost << " ";
    break;
  }
  return ost;
}