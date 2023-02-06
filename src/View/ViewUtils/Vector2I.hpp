#ifndef VECTOR_2I_HPP
#define VECTOR_2I_HPP

#include <Vector2.hpp>
#include <initializer_list>
#include <stdexcept>

namespace Utils {

struct Vector2I {
  int x; // NOLINT
  int y; // NOLINT

  Vector2I() = default;

  constexpr Vector2I(const int &xPos, const int &yPos) : x(xPos), y(yPos) {}
  constexpr Vector2I(const std::initializer_list<int> &pos)
      : x(*pos.begin()), y(*(pos.begin() + 1)) {
    if (pos.size() != 2) {
      throw std::runtime_error("Initializer list must have 2 elements");
    }
  }
  constexpr Vector2I(const Vector2 &rlV)
      : x(static_cast<int>(rlV.x)), y(static_cast<int>(rlV.y)) {}

  constexpr Vector2I(const raylib::Vector2 &rlV)
      : x(static_cast<int>(rlV.x)), y(static_cast<int>(rlV.y)) {}

  constexpr bool operator==(const Vector2 &other) const {
    return x == static_cast<int>(other.x) && y == static_cast<int>(other.y);
  }
  constexpr Vector2I operator+(const Vector2I &other) const {
    return {x + other.x, y + other.y};
  }
  constexpr Vector2I operator+(const Vector2 &other) const {
    return {x + static_cast<int>(other.x), y + static_cast<int>(other.y)};
  }

  // difference
  constexpr Vector2I operator-(const Vector2I &other) const {
    return {x - other.x, y - other.y};
  }
  constexpr Vector2I operator-(const Vector2 &other) const {
    return {x - static_cast<int>(other.x), y - static_cast<int>(other.y)};
  }

  // casting to Vector2
  constexpr operator Vector2() const {
    return {static_cast<float>(x), static_cast<float>(y)};
  }
  operator raylib::Vector2() const {
    return {static_cast<float>(x), static_cast<float>(y)};
  }

}; // Vector2I

} // namespace Utils

#endif // !VECTOR_2I_HPP
