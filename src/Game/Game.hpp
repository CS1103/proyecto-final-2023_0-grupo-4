#include "Config.hpp"
#include "Maze.hpp"
#include "View.hpp"

template <PLAYER_TYPE playerType> class GameBase {

public:
  GameBase(const Config &config, View &view);
  virtual void Run() = 0;

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
  Game(const Config &config, View &view)
      : GameBase<PLAYER_TYPE::HUMAN>(config, view) {
    player_name = "Human";
  }
};

template <>
class Game<PLAYER_TYPE::COMPUTER> : public GameBase<PLAYER_TYPE::COMPUTER> {
public:
  void Run() override;
  Game(const Config &config, View &view)
      : GameBase<PLAYER_TYPE::COMPUTER>(config, view) {
    player_name = "Human";
  }
};
