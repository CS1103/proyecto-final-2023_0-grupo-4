#include "View.hpp"
#include "Button.hpp"

using Utils::Vector2I;

void View::StartScreen() {

  // constexpr float TITLE_SIZE = 50;
  // constexpr std::string_view GAME_NAME = "Labyrinth game";
  // constexpr std::string_view FONT_PATH = "../src/assets/fonts/pixelplay.png";

  const Vector2I WINDOW_CENTER = window.GetSize() / 2;

  const Vector2I TITLE_POS = WINDOW_CENTER - Vector2I(0, 40);
  const Vector2I BUTTON_POS = WINDOW_CENTER + rl::Vector2(0, 40);

  const rl::Text TITLE = Utils::DefaultTitleText();
  Button button1 = ButtonBuilder(); //.name("beggin_game").pos(BUTTON_POS);

  while (!window.ShouldClose()) {

    if (button1.isClicked()) {
      return;
    }

    BeginDrawing();

    window.ClearBackground();

    background.Draw(0, 0);
    button1.Draw();

    TITLE.Draw(TITLE_POS);

    EndDrawing();
  }
}

Config View::GetConfig() {

  /* Settings
   * GAME_TYPE = BOT | HUMAN
   * TIMED = true | false
   * SIZE = {INT, INT}
   */
}
