#ifndef MAZE_TEST_TEXT_BUILDER_H
#define MAZE_TEST_TEXT_BUILDER_H
#include <raylib-cpp.hpp>

class TextBuilder;

class Text {
private:
    std::string_view text;
    float fontSize = 16;
    Color textColor = { 0, 0, 0, 0 };
    float spacing = 5;
    std::string_view font_path;
public:
    friend class  TextBuilder;
    static TextBuilder create();

    [[nodiscard]] const std::string_view &getText() const {
        return text;
    }

    [[nodiscard]] const float &getFontSize() const{
        return fontSize;
    }

    [[nodiscard]] const Color &getTextColor() const{
        return textColor;
    }

    [[nodiscard]] float getSpacing() const {
        return spacing;
    }

    [[nodiscard]] const std::string_view &getFontPath() const {
        return font_path;
    }

};

class TextBuilder {
private:
    Text text;
public:
    operator Text() const{
        return text;
    }

    TextBuilder& setText() {
        return *this;
    }
    TextBuilder& setText(std::string_view t) {
        text.text = t;
        return *this;
    }

    TextBuilder& setFontSize() {
        return *this;
    }
    TextBuilder& setFontSize(float sz) {
        text.fontSize = sz;
        return *this;
    }

    TextBuilder& setTextColor() {
        return *this;
    }
    TextBuilder& setTextColor(Color c) {
        text.textColor = c;
        return *this;
    }

    TextBuilder& setSpacing() {
        return *this;
    }
    TextBuilder& setSpacing(float sp) {
        text.spacing = sp; return *this;
    }

    TextBuilder& setFontPath() {
        return *this;
    }
    TextBuilder& setFontPath(std::string_view fp) {
        text.font_path = fp;
        return *this;
    }
};


int test(){
    Text text = TextBuilder()
            .setText("ae")
            .setFontSize(36)
            .setTextColor({ 0, 0, 0, 255 })
            .setSpacing(3)
            .setFontPath("");
    return 0;
}

#endif //MAZE_TEST_TEXT_BUILDER_H
