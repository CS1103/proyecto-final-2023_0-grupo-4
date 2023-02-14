#include "Game.hpp"

// explicit instantiation of abstact class

template class GameBase<PLAYER_TYPE::HUMAN>;
template class GameBase<PLAYER_TYPE::COMPUTER>;
