#ifndef VIEW_UTILS_HPP
#define VIEW_UTILS_HPP

#include "Builders.hpp"
#include <initializer_list>
#include <raylib-cpp.hpp>
#include <string>

namespace Utils {

namespace Validators {
bool Name(const std::string &input);
bool NumSmall(const std::string &input);
bool NumLarge(const std::string &input);

} // namespace Validators

const FontBuilder DefaultTitleFont();
const TextBuilder DefaultTitleText();

const FontBuilder DefaultButtonFont();
const TextBuilder DefaultButtonText();
const ButtonBuilder DefaultButton();

const FontBuilder DefaultTextBoxFont();
const TextBuilder DefaultTextBoxText();
const TextBoxBuilder DefaultTextBox();

} // namespace Utils

#endif // !VIEW_UTILS_HPP
