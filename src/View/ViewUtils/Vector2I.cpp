#include "Vector2I.hpp"
#include <stdexcept>
namespace Utils {

constexpr Vector2I::Vector2I(const Vector2 &rlV)
    : x(static_cast<int>(rlV.x)), y(static_cast<int>(rlV.y)) {}

constexpr Vector2I::Vector2I(const std::initializer_list<int> &pos) {
  if (pos.size() != 2) {
    throw std::runtime_error("Initializer list must have 2 elements");
  }
  x = *pos.begin();
  y = *(pos.begin() + 1);
}

constexpr Vector2I::Vector2I(const raylib::Vector2 &rlV)
    : x(static_cast<int>(rlV.x)), y(static_cast<int>(rlV.y)) {}

constexpr bool Vector2I::operator==(const Vector2 &other) const {
  return x == static_cast<int>(other.x) && y == static_cast<int>(other.y);
}
constexpr Vector2I Vector2I::operator+(const Vector2I &other) const {
  return {x + other.x, y + other.y};
}
constexpr Vector2I Vector2I::operator+(const Vector2 &other) const {
  return {x + static_cast<int>(other.x), y + static_cast<int>(other.y)};
}

// difference
constexpr Vector2I Vector2I::operator-(const Vector2I &other) const {
  return {x - other.x, y - other.y};
}
constexpr Vector2I Vector2I::operator-(const Vector2 &other) const {
  return {x - static_cast<int>(other.x), y - static_cast<int>(other.y)};
}

// casting to Vector2
constexpr Vector2I::operator Vector2() const {
  return {static_cast<float>(x), static_cast<float>(y)};
}
Vector2I::operator raylib::Vector2() const {
  return {static_cast<float>(x), static_cast<float>(y)};
}

} // namespace Utils
