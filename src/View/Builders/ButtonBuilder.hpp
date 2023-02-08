#ifndef BUTTON_BUILDER_HPP
#define BUTTON_BUILDER_HPP

#include "Vector2I.hpp"
#include <raylib-cpp.hpp>
#include "TextBuilder.hpp"
#include "Text.hpp"
#include "Button.hpp"

class ButtonBuilder: public raylib::Text{
public:
    operator Button() const{
        return button;
    }

    ButtonBuilder& m_text();
    ButtonBuilder& m_text(Text txt);

    ButtonBuilder& m_texture();
    ButtonBuilder& m_texture(rl::Texture texture);

    ButtonBuilder& m_pos();
    ButtonBuilder& m_pos(Utils::Vector2I vect2);

    /*
  ButtonBuilder() : texture(defaultButtonTexture()) {}
  raylib::Texture &texture;
  raylib::Text text;
  Utils::Vector2I pos{};*/


private:
    inline static raylib::Texture &defaultButtonTexture() {
    static raylib::Texture s_texture(
        "../src/assets/Textures/test_old_button.png");
    return s_texture;
    }
    Button button;
};

#endif // !BUTTON_BUILDER_HPP
