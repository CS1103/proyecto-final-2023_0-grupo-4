#include "ButtonBuilder.hpp"

ButtonBuilder &ButtonBuilder::m_text() {
    return *this;
}

ButtonBuilder &ButtonBuilder::m_text(raylib::Text txt) {
    button.m_text = txt;
    return *this;
}

ButtonBuilder &ButtonBuilder::m_texture() {
    return *this;
}

ButtonBuilder &ButtonBuilder::m_texture(rl::Texture texture) {
    button.m_texture = texture;
    return *this;
}

ButtonBuilder &ButtonBuilder::m_pos() {
    return *this;
}

ButtonBuilder &ButtonBuilder::m_pos(Utils::Vector2I vect2) {
    button.m_pos = vect2;
    return *this;
}




