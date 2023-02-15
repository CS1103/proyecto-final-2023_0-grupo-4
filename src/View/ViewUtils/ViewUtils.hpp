#ifndef VIEW_UTILS_HPP
#define VIEW_UTILS_HPP

#include "Builders.hpp"
#include "Vector2I.hpp"
#include <initializer_list>
#include <raylib-cpp.hpp>
#include <string>

namespace Utils {

namespace Validators {
bool Name(const std::string &input);
bool NumSmall(const std::string &input);
bool NumLarge(const std::string &input);

} // namespace Validators

const TextBuilder &DefaultTitleText(const Vector2I &pos);

const TextBuilder &DefaultButtonText(const Vector2I &pos);
const ButtonBuilder &DefaultButton(const Vector2I &pos);

const TextBuilder &DefaultTextBoxText(const Vector2I &pos);
const TextBoxBuilder &DefaultTextBox(const Vector2I &pos);

struct PositionCalc {

  explicit PositionCalc(const Vector2I &windowSize);

  [[nodiscard]] Vector2I GetCenter() const;

  Vector2I operator()(const uint8_t &widthPercentage,
                      const uint8_t &heightPercentge) const;

  Vector2I m_windowSize;
};

} // namespace Utils

#endif // !VIEW_UTILS_HPP
