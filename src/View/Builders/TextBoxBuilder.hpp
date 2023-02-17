#ifndef TEXT_BOX_BUILDER_HPP
#define TEXT_BOX_BUILDER_HPP

#include <Rectangle.hpp>
#include <Text.hpp>
#include <functional>

namespace rl = raylib;

struct TextBoxBuilder {

  raylib::Text text;

  // Rectangle stuff
  rl::Vector2 pos;
  rl::Vector2 size;
  Color color = WHITE;

  std::function<bool(const std::string &)> validator;

  TextBoxBuilder() = default;
  explicit TextBoxBuilder(
      const std::function<bool(const std::string &)> &validator);

  TextBoxBuilder &Pos(const rl::Vector2 &_pos);
  TextBoxBuilder &Size(const rl::Vector2 &_size);

private:
};

#endif // !TEXT_BOX_BUILDER_HPP
