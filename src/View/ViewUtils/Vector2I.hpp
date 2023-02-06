#ifndef VECTOR_2I_HPP
#define VECTOR_2I_HPP

#include <Vector2.hpp>
#include <initializer_list>

namespace Utils {

struct Vector2I {
  int x; // NOLINT
  int y; // NOLINT

  Vector2I() = default;

  inline constexpr Vector2I(const int &xPos, const int &yPos)
      : x(xPos), y(yPos) {}
  constexpr Vector2I(const std::initializer_list<int> &pos);

  constexpr Vector2I(const Vector2 &rlV);         // NOLINT
  constexpr Vector2I(const raylib::Vector2 &rlV); // NOLINT

  constexpr bool operator==(const Vector2 &other) const;

  constexpr Vector2I operator+(const Vector2I &other) const;
  constexpr Vector2I operator+(const Vector2 &other) const;
  constexpr Vector2I operator-(const Vector2I &other) const;
  constexpr Vector2I operator-(const Vector2 &other) const;

  // implicit casting
  constexpr operator Vector2() const; // NOLINT
  operator raylib::Vector2() const;   // NOLINT

}; // Vector2I

} // namespace Utils

#endif // !VECTOR_2I_HPP
