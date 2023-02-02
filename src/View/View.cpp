#include "View.hpp"

#include "Button.hpp"

void View::startScreen() {

  constexpr float TITLE_SIZE = 50;
  constexpr std::string_view GAME_NAME = "Labyrinth game";
  constexpr std::string_view FONT_PATH = "../src/assets/fonts/pixelplay.png";

  Button button1("Beggin game");

  const rl::Font TITLE_FONT(FONT_PATH.data());
  const rl::Text TITLE(TITLE_FONT, GAME_NAME.data(), TITLE_SIZE);

  const rl::Vector2 WINDOW_CENTER = {window.GetSize() / 2 -
                                     TITLE.MeasureEx() / 2};

  const rl::Vector2 TITLE_POS = WINDOW_CENTER - rl::Vector2(0, 40);
  const rl::Vector2 BUTTON_POS = WINDOW_CENTER + rl::Vector2(0, 40);

  while (!window.ShouldClose()) {
    BeginDrawing();

    window.ClearBackground();

    button1.Draw(BUTTON_POS);
    TITLE.Draw(TITLE_POS);

    if (button1.isClicked(BUTTON_POS)) {
      return;
    }

    EndDrawing();
  }
  throw std::runtime_error("Window closed");
}
