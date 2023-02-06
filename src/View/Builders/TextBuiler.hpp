#ifndef TEXT_BUILDER_HPP
#define TEXT_BUILDER_HPP

#include <Font.hpp>
#include <Text.hpp>

class FontBuilder {
public:
private:
};

class TextBuilder {
public:
  // casting to raylib::Text
  operator raylib::Text() const;

private:
};

#endif // !TEXT_BUILDER_HPP
