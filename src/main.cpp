#include "Game.hpp"
#include "View.hpp"
#include <functional>

int main() {

  View view;

  view.StartScreen();
  Config settings = view.GetConfig();

  if (settings.playerT == PLAYER_TYPE::HUMAN) {
    Game<PLAYER_TYPE::HUMAN> game(settings, view);
    game.Run();
  } else {
    Game<PLAYER_TYPE::COMPUTER> game(settings, view);
    game.Run();
  }

  // game.run();
}
