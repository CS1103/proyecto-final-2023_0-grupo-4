#include "ViewUtils.hpp"
namespace Utils {

namespace Validators {
bool Name(const std::string & /*input*/) { return true; }
bool NumSmall(const std::string & /*input*/) { return true; }
bool NumLarge(const std::string & /*input*/) { return true; }

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

} // namespace Utils
