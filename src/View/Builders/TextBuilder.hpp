#ifndef TEXT_BUILDER_HPP
#define TEXT_BUILDER_HPP

#include <Font.hpp>
#include <Text.hpp>

class TextBuilder
{
private:
    std::string text;
    Vector2 position;
    int fontSize;
    Color color;
    Font font;

public:
    TextBuilder();

    TextBuilder& Text(std::string);

    TextBuilder& Position(Vector2 position_);

    TextBuilder& FontSize(int fontSize_);

    TextBuilder& Color_(Color color_);

    TextBuilder& Font_(Font font_);

    void draw();

};
#endif // !TEXT_BUILDER_HPP
