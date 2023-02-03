#include "Maze.hpp"

class Config;

class Game {
public:
  Game(Config config, Maze maze);

private:
  Maze m_maze;
};
