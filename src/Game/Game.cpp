#include "Game.hpp"

#include <Bot.hpp>

using std::optional;
using MazeSteps = std::queue<square>;

[[maybe_unused]] static void PrintQueue(MazeSteps steps) {
  while (!steps.empty()) {
    auto front = steps.front();

    std::cout << static_cast<int>(front.first) << "  "
              << static_cast<int>(front.second) << std::endl;
    steps.pop();
  }
}

template <PLAYER_TYPE PLAYER_TYPE>
GameBase<PLAYER_TYPE>::GameBase(const Config &config, View &view)
    : m_config(config), m_maze(config.board_size), r_view(view) {}

void Game<PLAYER_TYPE::HUMAN>::Run() {
  r_view.LoadMaze(m_maze.GetMaze(), m_maze.GetStart(), m_maze.GetGoal());
  r_view.HumanMode(m_config.timed);
}

void Game<PLAYER_TYPE::COMPUTER>::Run() {

  Bot bot;

  optional<MazeSteps> solution = std::nullopt;
  optional<MazeSteps> searched = std::nullopt;

  r_view.LoadMaze(m_maze.GetMaze(), /*fullscreen*/ false);

  bool finish = false;
  ALGORITHM algorithm{};

  do {

    auto view_return = r_view.BotMode(solution, searched);

    algorithm = view_return.first;
    finish = view_return.second;

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

  } while (!finish);
}

// explicit instantiation of abstact class

template class GameBase<PLAYER_TYPE::HUMAN>;
template class GameBase<PLAYER_TYPE::COMPUTER>;
