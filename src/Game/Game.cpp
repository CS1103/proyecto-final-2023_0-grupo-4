#include "Game.hpp"

#include <Bot.hpp>

using std::optional;
using MazeSteps = std::queue<square>;

template <PLAYER_TYPE PLAYER_TYPE>

GameBase<PLAYER_TYPE>::GameBase(const Config &config, View &view)
    : m_config(config), m_maze(config.board_size), r_view(view) {
  std::cout << "GameBase constructor" << std::endl;
}

void Game<PLAYER_TYPE::HUMAN>::Run() { std::cout << "Human game run"; }

void Game<PLAYER_TYPE::COMPUTER>::Run() {

  std::cout << "Computer game run" << std::endl;

  Bot bot;

  optional<MazeSteps> solution = std::nullopt;
  optional<MazeSteps> searched = std::nullopt;

  r_view.LoadMaze(m_maze.GetMaze());

  bool finish = false;
  ALGORITHM algorithm{};

  do {

    auto view_return = r_view.BotMode(solution, searched);
    std::cout << "view finished" << std::endl;

    algorithm = view_return.first;
    finish = view_return.second;

    switch (algorithm) {
    case ALGORITHM::DFS:
      std::cout << "bot solve DFS" << std::endl;
      bot.Solve<ALGORITHM::DFS>(m_maze);
      std::cout << "bot solve DFS finished" << std::endl;

      break;
    case ALGORITHM::BFS:
      bot.Solve<ALGORITHM::BFS>(m_maze);
      break;
    case ALGORITHM::GBFS:
      std::cout << "bot solve GBFS started" << std::endl;
      bot.Solve<ALGORITHM::GBFS>(m_maze);
      std::cout << "bot solve GBFS finished" << std::endl;

      break;
    case ALGORITHM::A_STAR:
      bot.Solve<ALGORITHM::A_STAR>(m_maze);
      break;
    }
    solution = bot.GetSolution();
    searched = bot.GetSearchedPath();

  } while (!finish);
}

// explicit instantiation of abstact class

template class GameBase<PLAYER_TYPE::HUMAN>;
template class GameBase<PLAYER_TYPE::COMPUTER>;
