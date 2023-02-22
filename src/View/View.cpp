#include "View.hpp"
#include "Button.hpp"
#include "Config.hpp"
#include "TextBox.hpp"

#include "ViewUtils.hpp"

using std::optional;
using Utils::Vector2I;

void View::StartScreen() {

  const Vector2I WINDOW_CENTER = window.GetSize() / 2;
  const Vector2I TITLE_POS = WINDOW_CENTER - Vector2I(0, 40);
  const Vector2I BUTTON_POS = WINDOW_CENTER + rl::Vector2(0, 40);

  const rl::Text TITLE = Utils::DefaultTitleText("MAZE GAME");
  Button button1 = Utils::DefaultButton("Start!", BUTTON_POS);

  while (!window.ShouldClose()) {

    if (button1.IsClicked()) {
      return;
    }

    BeginDrawing();

    window.ClearBackground();

    background.Draw();
    button1.Draw();
    TITLE.Draw(TITLE_POS);

    EndDrawing();
  }
}

Config View::GetConfig() {

  // Calculating positions
  Utils::PositionCalc calc(window.GetSize());

  constexpr int HORIZONTAL_OPTIONS_START = 45;

  const Vector2I WIDTH_POSITION = calc(HORIZONTAL_OPTIONS_START - 10, 40);
  const Vector2I HEIGHT_POSITION = calc(HORIZONTAL_OPTIONS_START + 10, 40);
  const Vector2I IS_BOT_POSITION = calc(HORIZONTAL_OPTIONS_START, 20);
  const Vector2I IS_TIMED_POSITION = calc(HORIZONTAL_OPTIONS_START, 65);
  const Vector2I START_POSITION = calc(35, 80);

  auto size_validator = [](const std::string &str) {
    if (str.empty() || str.size() > 3) {
      return false;
    }
    return std::all_of(str.begin(), str.end(), ::isdigit);
  };

  TextBox width_box = Utils::DefaultTextBox(
      WIDTH_POSITION, {100, 50}) /*.validator(size_validator)*/;
  TextBox height_box = Utils::DefaultTextBox(HEIGHT_POSITION, {100, 50})
                           .Validator(size_validator);

  Button is_bot_button = Utils::DefaultButton("BOT", IS_BOT_POSITION);
  Button is_human_button = Utils::DefaultButton(
      "HUMAN", IS_BOT_POSITION + Vector2I(is_bot_button.GetSize().x, 0));

  Button is_timed_button = Utils::DefaultButton("timed", IS_TIMED_POSITION);
  Button is_not_timed_button = Utils::DefaultButton(
      "not_timed",
      IS_TIMED_POSITION + Vector2I(is_timed_button.GetSize().x, 0));

  Button start_button = Utils::DefaultButton("start game", START_POSITION);

  optional<bool> is_bot;
  optional<bool> is_timed;
  optional<uint8_t> width;
  optional<uint8_t> height;

  bool width_valid = false;
  bool height_valid = false;

  while (!window.ShouldClose()) {

    if (start_button.IsClicked()) {

      if (!is_bot.has_value() || !is_timed.has_value() || !width.has_value() ||
          !height.has_value() || !width_valid || !height_valid) {

        std::cout << std::boolalpha << is_bot.value();
        std::cout << '\n';
        std::cout << std::boolalpha << is_timed.value();
        std::cout << '\n';
        std::cout << width.value();
        std::cout << '\n';
        std::cout << height.value();
        std::cout << '\n';
        std::cout << width_valid;
        std::cout << '\n';
        std::cout << height_valid;
        std::cout << '\n';

        std::cout << "Not all options are set" << std::endl;
        throw;
      }

      PLAYER_TYPE player_type =
          is_bot.value() ? PLAYER_TYPE::HUMAN : PLAYER_TYPE::COMPUTER;
      return {player_type, {width.value(), height.value()}, is_timed.value()};
    }

    if (is_bot_button.IsClicked()) {
      is_bot = true;
      is_bot_button.Highlight();
      is_human_button.UnHighlight();

    } else if (is_human_button.IsClicked()) {
      is_bot = false;
      is_bot_button.UnHighlight();
      is_human_button.Highlight();
    }

    if (is_timed_button.IsClicked()) {
      is_timed = true;
      is_timed_button.Highlight();
      is_not_timed_button.UnHighlight();

    } else if (is_not_timed_button.IsClicked()) {
      is_timed = false;
      is_timed_button.UnHighlight();
      is_not_timed_button.Highlight();
    }

    width_box.CheckFocus();
    width_valid = width_box.HandleInput().value_or(false);

    if (width_valid) {
      std::cout << "width valid" << std::endl;
      try {
        width = std::stoi("");
      } catch (const std::invalid_argument &) {
        std::cout << "stoi unsuccesfull" << std::endl;
      }
      std::cout << "stoi succes" << std::endl;

      // width = std::stoi(width_box.GetText());
    }

    height_box.CheckFocus();
    height_valid = height_box.HandleInput().value_or(false);
    if (height_valid) {
      // height = std::stoi(height_box.GetText());
    }

    if (width_box.CheckCollision(GetMousePosition()) ||
        height_box.CheckCollision(GetMousePosition())) {

      SetMouseCursor(MOUSE_CURSOR_IBEAM);
      // CRASHES

    } else {

      SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    BeginDrawing();
    window.ClearBackground();

    background.Draw(0, 0);
    DrawAll(width_box, height_box, is_bot_button, is_human_button,
            is_timed_button, is_not_timed_button);
    EndDrawing();
  }
  throw std::runtime_error("Window closed");
}

void View::PrintPath(const Maze &maze,
                     const std::unordered_set<square, Maze::HashPair> &path) {}
