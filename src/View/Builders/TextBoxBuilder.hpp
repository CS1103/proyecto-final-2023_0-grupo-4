#ifndef TEXT_BOX_BUILDER_HPP
#define TEXT_BOX_BUILDER_HPP

#include "Vector2I.hpp"
#include <Text.hpp>
#include <functional>

struct TextBoxBuilder {

  raylib::Text text;
  Utils::Vector2I pos;
  std::function<bool(std::string)> validator;

private:
};

#endif // !TEXT_BOX_BUILDER_HPP
