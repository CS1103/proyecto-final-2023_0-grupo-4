#include "View.hpp"
#include "Button.hpp"
#include "Config.hpp"
#include "TextBox.hpp"

#include "ViewUtils.hpp"

using std::optional;
using Utils::Vector2I;

template <typename T>
concept Drawable = requires(T obj) {
                     { obj.Draw() } -> std::same_as<void>;
                   };

template <typename... Args>
  requires(Drawable<Args> && ...)
static void DrawAll(Args &&...args) {
  (args.Draw(), ...);
}

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

/*
 *     if (is_bot_button.IsClicked()) {
      is_bot = true;
      is_bot_button.Highlight();
      is_human_button.UnHighlight();

    } else if (is_human_button.IsClicked()) {
      is_bot = false;
      is_bot_button.UnHighlight();
      is_human_button.Highlight();
    }
*/
static optional<bool> HandleDualButton(Button &button1, Button &button2) {

  if (button1.IsClicked()) {
    button1.Highlight();
    button2.UnHighlight();
    return true;
  }
  if (button2.IsClicked()) {
    button2.Highlight();
    button1.UnHighlight();
    return false;
  }
  return std::nullopt;
}

Config View::GetConfig() {

  Utils::PositionCalc calc(window.GetSize());

  constexpr int HORIZONTAL_OPTIONS_START = 45;

  // Calculating positions
  const Vector2I WIDTH_POSITION = calc(HORIZONTAL_OPTIONS_START - 10, 40);
  const Vector2I HEIGHT_POSITION = calc(HORIZONTAL_OPTIONS_START + 10, 40);
  const Vector2I IS_BOT_POSITION = calc(HORIZONTAL_OPTIONS_START, 20);
  const Vector2I IS_TIMED_POSITION = calc(HORIZONTAL_OPTIONS_START, 65);
  const Vector2I START_POSITION = calc(35, 80);

  const Vector2I TEXT_BOX_SIZE = {100, 50};

  TextBox width_box = Utils::DefaultTextBox(WIDTH_POSITION, TEXT_BOX_SIZE)
                          .Validator(Utils::Validators::NumSmall);

  TextBox height_box = Utils::DefaultTextBox(HEIGHT_POSITION, TEXT_BOX_SIZE)
                           .Validator(Utils::Validators::NumSmall);

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

      if (is_bot.has_value() && is_timed.has_value() && width.has_value() &&
          height.has_value() && width_valid && height_valid &&
          is_bot.has_value()) {

        PLAYER_TYPE player_type =
            is_bot.value() ? PLAYER_TYPE::HUMAN : PLAYER_TYPE::COMPUTER;
        return {player_type, {width.value(), height.value()}, is_timed.value()};
      }
    }

    is_bot = HandleDualButton(is_bot_button, is_human_button);

    is_timed = HandleDualButton(is_timed_button, is_not_timed_button);

    width_box.CheckFocus();
    width_box.HandleInput();

    if (width_box.TextIsValid()) {
      try {
        width = std::stoi(width_box.GetText());
      } catch (const std::invalid_argument &) {
      }
    } else {
      width = std::nullopt;
    }

    height_box.CheckFocus();
    height_box.HandleInput();

    if (height_box.TextIsValid()) {
      try {
        height = std::stoi(height_box.GetText());
      } catch (const std::invalid_argument &) {
      }
    } else {
      height = std::nullopt;
    }

    if (width_box.CheckCollision(GetMousePosition()) ||
        height_box.CheckCollision(GetMousePosition())) {
      SetMouseCursor(MOUSE_CURSOR_IBEAM);
    } else {
      SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    BeginDrawing();
    window.ClearBackground();

    background.Draw(0, 0);
    DrawAll(width_box, height_box, is_bot_button, is_human_button,
            is_timed_button, is_not_timed_button, start_button);
    EndDrawing();
  }
  throw std::runtime_error("Window closed");
}

void View::LoadMaze(const maze_t &maze) {
  ViewMaze new_maze(maze);

  this->view_maze = ViewMaze(maze);
}

std::pair<ALGORITHM, bool> View::BotMode(optional<MazeSteps> solution,
                                         optional<MazeSteps> searched) {

  if (!view_maze.has_value()) {
    throw std::runtime_error("View::BotMode: maze not loaded");
  }

  Utils::PositionCalc calc(window.GetSize());
  constexpr int HORIZONTAL_OPTIONS_START = 65;

  const Vector2I DFS_POSITION = calc(HORIZONTAL_OPTIONS_START, 20);
  const Vector2I BFS_POSITION = calc(HORIZONTAL_OPTIONS_START, 40);
  const Vector2I GBFS_POSITION = calc(HORIZONTAL_OPTIONS_START, 60);
  const Vector2I A_STAR_POSITION = calc(HORIZONTAL_OPTIONS_START, 85);

  const Vector2I END_POSITION = calc(35, 80);

  Button dfs_button = Utils::DefaultButton("DFS", DFS_POSITION);
  Button bfs_button = Utils::DefaultButton("BFS", BFS_POSITION);
  Button gbfs_button = Utils::DefaultButton("GBFS", GBFS_POSITION);
  Button a_star_button = Utils::DefaultButton("A*", A_STAR_POSITION);

  Button end_button = Utils::DefaultButton("end", END_POSITION);

  uint frame_count = 0;

  while (!window.ShouldClose()) {

    if (dfs_button.IsClicked()) {
      return {ALGORITHM::DFS, false};
    }
    if (bfs_button.IsClicked()) {
      return {ALGORITHM::BFS, false};
    }
    if (gbfs_button.IsClicked()) {
      return {ALGORITHM::GBFS, false};
    }
    if (a_star_button.IsClicked()) {
      return {ALGORITHM::A_STAR, false};
    }
    if (end_button.IsClicked()) {
      return {ALGORITHM::BFS, true};
    }

    // Drawing
    DrawAll(dfs_button, bfs_button, gbfs_button, a_star_button);

    view_maze->Draw();

    if (!solution.has_value() || !searched.has_value()) {
      continue;
    }

    frame_count++;

    if (!searched->empty()) {

      if (frame_count % 10 == 0) {
        auto current = searched->front();
        searched->pop();
        auto next = searched->front();

        view_maze->DrawSearched(current, next);
      }
      continue;
    }
    if (!solution->empty()) {

      if (frame_count % 10 == 0) {
        auto current = solution->front();
        solution->pop();
        auto next = solution->front();

        view_maze->DrawSolution(current, next);
      }
      continue;
    }
  }

  return {ALGORITHM::BFS, true};
}
