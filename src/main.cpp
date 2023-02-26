#include "Game.hpp"
#include "View.hpp"
#include <functional>

int main() {

  View view;

  view.StartScreen();
  Config settings = view.GetConfig();

  if (settings.playerT == PLAYER_TYPE::HUMAN) {
    std::cout << "human_mode" << '\n';
    Game<PLAYER_TYPE::HUMAN> game(settings, view);
    game.Run();
  } else {
    std::cout << "pc_mode" << '\n';
    Game<PLAYER_TYPE::COMPUTER> game(settings, view);
    game.Run();
  }

  // game.run();
}
