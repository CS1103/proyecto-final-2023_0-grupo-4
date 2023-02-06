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

const FontBuilder DEFAULT_TITLE_FONT;
const TextBuilder DEFAULT_TITLE_TEXT;

const FontBuilder DEFAULT_BUTTON_FONT;
const TextBuilder DEFAULT_BUTTON_TEXT;
const ButtonBuilder DEFAULT_BUTTON;

const FontBuilder DEFAULT_TEXT_BOX_FONT;
const TextBuilder DEFAULT_TEXT_BOX_TEXT;
const TextBoxBuilder DEFAULT_TEXT_BOX;

} // namespace Utils

#endif // !VIEW_UTILS_HPP
