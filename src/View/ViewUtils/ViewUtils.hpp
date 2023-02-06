#ifndef VIEW_UTILS_HPP
#define VIEW_UTILS_HPP

#include <initializer_list>
#include <raylib-cpp.hpp>
#include <string>

namespace Utils {

namespace Validators {
bool Name(const std::string &input) { return true; }
bool NumSmall(const std::string &input) { return true; }
bool NumLarge(const std::string &input) { return true; }

} // namespace Validators

struct Vector2I {
  int x; // NOLINT
  int y; // NOLINT

  Vector2I(const int &xPos, const int &yPos) : x(xPos), y(yPos) {}
  Vector2I(const std::initializer_list<int> &pos);

  Vector2I(const Vector2 &rlV)
      : x(static_cast<int>(rlV.x)), y(static_cast<int>(rlV.y)) {}
  Vector2I(const raylib::Vector2 &rlV)
      : x(static_cast<int>(rlV.x)), y(static_cast<int>(rlV.y)) {}

  bool operator==(const Vector2 &other) const {
    return x == static_cast<int>(other.x) && y == static_cast<int>(other.y);
  }

  // sum
  Vector2I operator+(const Vector2I &other) const {
    return {x + other.x, y + other.y};
  }
  Vector2I operator+(const Vector2 &other) const {
    return {x + static_cast<int>(other.x), y + static_cast<int>(other.y)};
  }

  // difference
  Vector2I operator-(const Vector2I &other) const {
    return {x - other.x, y - other.y};
  }
  Vector2I operator-(const Vector2 &other) const {
    return {x - static_cast<int>(other.x), y - static_cast<int>(other.y)};
  }

  // casting to Vector2
  operator Vector2() const {
    return {static_cast<float>(x), static_cast<float>(y)};
  }
  operator raylib::Vector2() const {
    return {static_cast<float>(x), static_cast<float>(y)};
  }
};

// class FontBuilder {

//   operator raylib::Font() const {}

//   FontBuilder()
// };

FontBuilder DEFAULT_TITLE_FONT() {
  static rl::Font default_title_font(DEFAULT_FONT_PATH.data(),
                                     DEFAULT_FONT_SIZE, // NOLINT
                                     nullptr, DEFAULT_MAX_TEXT);
  return default_title_font;
}

// ButtonBuilder DEFAULT_BUTTON();
// ButtonBuilder DEFAULT_TEXT();
// ButtonBuilder DEFAULT_BUTTON_TEXT();

// TextBuilder DEFAULT_TITLE_TEXT(DEFAULT_TITLE_FONT() SIZE 50 VALUE "Title");

// TextBuilder DEFAULT_BUTTON_TEXT();
// TextBuilder DEFAULT_TEXT_BOX_TEXT();

// FontBuilder DEFAULT_BUTTON_FONT();
// FontBuilder DEFAULT_TEXT_BOX_FONT();

} // namespace Utils

#endif // !VIEW_UTILS_HPP
