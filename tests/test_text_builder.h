#ifndef MAZE_TEST_TEXT_BUILDER_H
#define MAZE_TEST_TEXT_BUILDER_H
#include <raylib-cpp.hpp>

typedef struct text_build {
    std::string_view text;
    float fontSize;
    Color textColor;
    float spacing;
    std::string_view font_path;

} Text_build;
typedef struct TextBuilder {
    std::string_view text;
    float fontSize;
    Color textColor;
    float spacing;
    std::string_view font_path;
    TextBuilder() : text("Iorem Ipsum"), fontSize(24), textColor({ 0, 0, 0, 0 }), spacing(5), font_path("") {}
    TextBuilder& setText(std::string_view t) { text = t; return *this; }
    TextBuilder& setFontSize(float sz) { fontSize = sz; return *this; }
    TextBuilder& setTextColor(Color c) { textColor = c; return *this; }
    TextBuilder& setSpacing(float sp) { spacing = sp; return *this; }
    Text_build build() {
        Text_build t;
        t.text = text;
        t.fontSize = fontSize;
        t.textColor = textColor;
        t.spacing = spacing;
        t.font_path = font_path;
        return t;
    }
} TextBuilder;


#endif //MAZE_TEST_TEXT_BUILDER_H
