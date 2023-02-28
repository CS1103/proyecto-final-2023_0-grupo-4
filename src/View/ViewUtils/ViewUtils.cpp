#include "ViewUtils.hpp"

#include <utility>
namespace Utils {

namespace Validators {
bool Name(const std::string & /*input*/) { return true; }
bool NumSmall(const std::string & /*input*/) { return true; }
bool NumLarge(const std::string & /*input*/) { return true; }
bool None(const std::string & /*input*/) { return true; }

} // namespace Validators

PositionCalc::PositionCalc(const Vector2I &windowSize)
    : m_windowSize(windowSize) {}

Vector2I PositionCalc::GetCenter() const {
  return Vector2I{m_windowSize.x / 2, m_windowSize.y / 2};
}

Vector2I PositionCalc::operator()(const uint8_t &widthPercentage,
                                  const uint8_t &heightPercentge) const {
  if (widthPercentage > 100 || heightPercentge > 100) {
    throw std::invalid_argument("Percentage must be between 0 and 100");
  }
  return {m_windowSize.x * widthPercentage / 100,
          m_windowSize.y * heightPercentge / 100};
}

TextBuilder DefaultTitleText(std::string _text) {
  static TextBuilder default_title = TextBuilder().FontSize(40).Color(WHITE);
  return default_title.Text(std::move(_text));
}

TextBuilder DefaultButtonText() {
  static TextBuilder default_button_text =
      TextBuilder().FontSize(50).Color(BLACK);
  return default_button_text;
}
TextBuilder DefaultButtonText(std::string _text) {
  return DefaultButtonText().Text(std::move(_text));
}

ButtonBuilder DefaultButton(std::string _text, const Vector2I &pos) {
  static ButtonBuilder default_button =
      ButtonBuilder().Texture(ButtonBuilder::DefaultButtonTexture());
  return default_button.Pos(pos).Text(DefaultButtonText(std::move(_text)));
}

TextBuilder DefaultTextBoxText() {
  static TextBuilder default_text_box_text =
      TextBuilder().FontSize(20).Color(BLACK);
  return default_text_box_text;
}
TextBoxBuilder
DefaultTextBox(const rl::Vector2 &_pos, const rl::Vector2 &_size,
               std::function<bool(const std::string &)> _validator) {
  static TextBoxBuilder default_text_box = TextBoxBuilder();
  return default_text_box.Pos(_pos)
      .Size(_size)
      .Text(DefaultTextBoxText())
      .Validator(std::move(_validator));
}

} // namespace Utils
