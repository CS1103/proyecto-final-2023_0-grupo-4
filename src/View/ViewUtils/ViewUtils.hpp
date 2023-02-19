#ifndef VIEW_UTILS_HPP
#define VIEW_UTILS_HPP

#include "Builders.hpp"
#include "Vector2I.hpp"
#include <initializer_list>
#include <string>

namespace Utils {

namespace Validators {
bool Name(const std::string &input);
bool NumSmall(const std::string &input);
bool NumLarge(const std::string &input);
bool None(const std::string &input);

} // namespace Validators

TextBuilder DefaultTitleText(std::string _text);

TextBuilder DefaultButtonText();
TextBuilder DefaultButtonText(std::string _text);
ButtonBuilder DefaultButton(std::string _text, const Vector2I &pos);

TextBuilder DefaultTextBoxText();
TextBoxBuilder DefaultTextBox(const rl::Vector2 &_pos, const rl::Vector2 &_size,
                              const std::function<bool(const std::string &)>
                                  &validator = Utils::Validators::None);

struct PositionCalc {

  explicit PositionCalc(const Vector2I &windowSize);

  [[nodiscard]] Vector2I GetCenter() const;

  Vector2I operator()(const uint8_t &widthPercentage,
                      const uint8_t &heightPercentge) const;

  Vector2I m_windowSize;
};

} // namespace Utils

#endif // !VIEW_UTILS_HPP
