#include "Config.hpp"
#include "Maze.hpp"
#include "View.hpp"

template <PLAYER_TYPE playerType> class GameBase {

public:
  virtual ~GameBase() = default;
  GameBase(const GameBase &) = delete;
  GameBase(GameBase &&) = delete;
  GameBase &operator=(const GameBase &) = delete;
  GameBase &operator=(GameBase &&) = delete;
  virtual void Run() = 0;
  GameBase(const Config &config, View &view) : m_config(config), r_view(view) {}

protected:
  Config m_config;
  Maze m_maze;
  std::string player_name;
  View &r_view;
};

template <PLAYER_TYPE playerType> class Game : public GameBase<playerType> {};

template <>
class Game<PLAYER_TYPE::HUMAN> : public GameBase<PLAYER_TYPE::HUMAN> {
public:
  void Run() override;
  Game(const Config &config, View &view) : GameBase(config, view) {}
};

template <>
class Game<PLAYER_TYPE::COMPUTER> : public GameBase<PLAYER_TYPE::COMPUTER> {
public:
  void Run() override;
  Game(const Config &config, View &view) : GameBase(config, view) {}
};

// extern explicit instantiation

extern template class GameBase<PLAYER_TYPE::HUMAN>;
extern template class GameBase<PLAYER_TYPE::COMPUTER>;
