#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <cstdint>
#include <tuple>

enum class PLAYER_TYPE { HUMAN, COMPUTER };

struct BoardSize {
  BoardSize(const uint8_t &widthP, const uint8_t &heightP)
      : width(widthP), height(heightP) {}
  uint8_t width;
  uint8_t height;
};

struct Config {

  Config(const PLAYER_TYPE &_playerT, const BoardSize &_size,
         const bool &_timed)
      : playerT(_playerT), timed(_timed), board_size(_size) {}

  PLAYER_TYPE playerT;
  bool timed;
  BoardSize board_size;
};

#endif // !CONFIG_HPP
