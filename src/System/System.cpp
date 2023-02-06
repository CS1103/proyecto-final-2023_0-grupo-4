#include "System.hpp"
#include "../Bot/Bot.hpp"
#include "../Maze/Maze.hpp"
#include "Utils.hpp"
#include <algorithm>

void System::run() {

  // m_vista.startScreen();

  // SQUARE_TYPE W = SQUARE_TYPE::WALL;  // NOLINT
  // SQUARE_TYPE E = SQUARE_TYPE::EMPTY; // NOLINT
  // SQUARE_TYPE G = SQUARE_TYPE::GOAL;  // NOLINT
  // SQUARE_TYPE S = SQUARE_TYPE::START; // NOLINT

  // [[maybe_unused]] std::vector<std::vector<SQUARE_TYPE>> board = {
  //     {W, W, W, W, W, W, W, W},
  //     {W, E, E, E, E, E, E, W},
  //     {W, E, W, W, W, W, W, W},
  //     {W, E, W, W, E, W, W, W},
  //     {W, E, W, W, E, W, W, W},
  //     {W, E, W, W, E, E, E, W},
  //     {W, E, W, W, E, W, E, W},
  //     {W, E, E, W, S, W, E, W},
  //     {W, W, E, W, E, W, E, W},
  //     {W, E, E, E, E, W, E, W},
  //     {W, W, E, W, W, W, W, W},
  //     {W, E, E, E, E, E, E, W},
  //     {W, W, E, W, W, W, G, W},
  //     {W, W, W, W, W, W, W, W}

  // };

  Maze tab;
  Bot bot;
  // bot.solve<ALGORITHM::BFS>(tab);
  // bot.solve<ALGORITHM::DFS>(tab);
  // bot.solve<ALGORITHM::A_STAR>(tab);
  // bot.solve<ALGORITHM::A_STAR>(tab);
  // tab.paintPath(bot.getSolution(), bot.getSearchedPath());
  // tab.printMaze();
  // for (const auto &sq : bot.getSearchedPath()) {
  //   std::cout << static_cast<int>(sq.first) << "  "
  //             << static_cast<int>(sq.second) << std::endl;
  // }
  auto empty_maze = tab.getMaze();
  auto current = tab.getStart();

  std::vector<square> options;
  std::unordered_set<square, Maze::HashPair> path;
  path.emplace(current);

  ulong choice = 0;

  while (current != tab.getGoal()) {

    for (const auto &row : empty_maze) {
      for (const auto &sq : row) {
        std::cout << sq;
      }
      std::cout << std::endl;
    }

    options.clear();

    for (const auto &sqr : path) {
      auto neighbors = tab.getNeighbors(sqr);
      for (const auto &n : neighbors) {
        if (empty_maze[n.first][n.second] != SQUARE_TYPE::GOAL) {
          options.emplace_back(n);
        }
      }
    }

    // remove options that are already in the path
    options.erase(std::remove_if(options.begin(), options.end(),
                                 [&path](const auto &sq) {
                                   return std::find(path.begin(), path.end(),
                                                    sq) != path.end();
                                 }),
                  options.end());
    int const c_first = current.first;
    int const c_sec = current.second;
    std::cout << "Current position: " << c_first << " " << c_sec
              << std::endl;
    std::cout << "Options: " << std::endl;
    for (const auto &option : options) {
      std::cout << static_cast<int>(option.first) << " "
                << static_cast<int>(option.second) << std::endl;
    }
    std::cout << "Choose [";
    auto opt_count = 0;
    for (ulong i = 0; i < options.size(); i++) {
      opt_count++;
      std::cout << opt_count << ", ";
    }
    std::cout << "]\n";
    std::cin >> choice;

    current = options[choice - 1];

    empty_maze[current.first][current.second] = SQUARE_TYPE::PATH;
    path.emplace(current);
  }

  // Ideal working scenario
  // Pseudocode!!

  /*

  view.startGame();
  Config settings = view.getConfig() Maze maze(settings.boardSettings);

  if (settings.humanGame) {

    Game game<GAME_TYPE::HUMAN>(settings, maze, view ref);
  } else {

    Game game<GAME_TYPE::BOT>(settings, maze, view ref);
  }

  game.run();

    */
}
