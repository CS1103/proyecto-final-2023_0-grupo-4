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

    std::cout << "Computer player(main)" << std::endl;

    Game<PLAYER_TYPE::COMPUTER> game(settings, view);

    std::cout << "Computer player(main) end" << std::endl;

    game.Run();
  }
}
