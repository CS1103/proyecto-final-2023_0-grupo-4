#include "Game.hpp"

void Game<PLAYER_TYPE::HUMAN>::Run() {}
void Game<PLAYER_TYPE::COMPUTER>::Run() {}

// explicit instantiation of abstact class

template class GameBase<PLAYER_TYPE::HUMAN>;
template class GameBase<PLAYER_TYPE::COMPUTER>;
