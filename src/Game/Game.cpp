#include "Game.hpp"

#include <Bot.hpp>

using std::optional;
using MazeSteps = std::queue<square>;

template <PLAYER_TYPE PLAYER_TYPE>

GameBase<PLAYER_TYPE>::GameBase(const Config &config, View &view)
    : m_config(config), m_maze(config.board_size), r_view(view) {}

void Game<PLAYER_TYPE::HUMAN>::Run() {}
void Game<PLAYER_TYPE::COMPUTER>::Run() {

  std::cout << "Computer mode" << std::endl;

  Bot bot;

  optional<MazeSteps> solution;
  optional<MazeSteps> searched;

  r_view.LoadMaze(m_maze.GetMaze());

  do {
    auto [algorithm, finish] = r_view.BotMode(solution, searched);

    switch (algorithm) {
    case ALGORITHM::DFS:
      bot.Solve<ALGORITHM::DFS>(m_maze);
      break;
    case ALGORITHM::BFS:
      bot.Solve<ALGORITHM::BFS>(m_maze);
      break;
    case ALGORITHM::GBFS:
      bot.Solve<ALGORITHM::GBFS>(m_maze);
      break;
    case ALGORITHM::A_STAR:
      bot.Solve<ALGORITHM::A_STAR>(m_maze);
      break;
    }
    solution = bot.GetSolution();
    searched = bot.GetSearchedPath();

  } while (true);
}

// explicit instantiation of abstact class

template class GameBase<PLAYER_TYPE::HUMAN>;
template class GameBase<PLAYER_TYPE::COMPUTER>;
