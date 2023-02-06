#include "View.hpp"
#include "Button.hpp"

using rl::Text;
using Utils::Vector2I;

void View::startScreen() {

  constexpr float TITLE_SIZE = 50;
  constexpr std::string_view GAME_NAME = "Labyrinth game";
  constexpr std::string_view FONT_PATH = "../src/assets/fonts/pixelplay.png";

  const Text TITLE(rl::Font(FONT_PATH.data()), GAME_NAME.data(), TITLE_SIZE);

  const Text TITLE = Utils::DEFAULT_TITLE_TEXT;

  // Button button1("Beggin game");
  Button button1 = ButtonBuilder().name("beggin_game");

  const Vector2I WINDOW_CENTER =
      Vector2I({window.GetSize() / 2 - TITLE.MeasureEx() / 2});
  const Vector2I TITLE_POS = WINDOW_CENTER - Vector2I(0, 40);
  const Vector2I BUTTON_POS = WINDOW_CENTER + rl::Vector2(0, 40);

  while (!window.ShouldClose()) {

    if (button1.isClicked(BUTTON_POS)) {
      return;
    }

    BeginDrawing();

    window.ClearBackground();

    background.Draw(0, 0);
    button1.Draw(BUTTON_POS);

    TITLE.Draw(TITLE_POS);

    EndDrawing();
  }
}

Config View::getConfig() {

  /* Settings
   * GAME_TYPE = BOT | HUMAN
   * TIMED = true | false
   * SIZE = {INT, INT}
   * 1
   */
}
