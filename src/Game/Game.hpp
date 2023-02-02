#include "Maze.hpp"

class Game {
public:
  Game() = default;
  Game(Game &&) = default;
  Game(const Game &) = default;
  Game &operator=(Game &&) = default;
  Game &operator=(const Game &) = default;
  ~Game() = default;

private:
};
