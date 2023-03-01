#include "View.hpp"
#include "Button.hpp"
#include "Config.hpp"
#include "TextBox.hpp"

#include "ViewUtils.hpp"
#include <chrono>

constexpr int MAX_TIME = 5;

using std::optional;
using Utils::Vector2I;
using uint = unsigned int;

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
            is_bot.value() ? PLAYER_TYPE::COMPUTER : PLAYER_TYPE::HUMAN;

        return {player_type, {width.value(), height.value()}, is_timed.value()};
      }
    }

    is_bot = HandleDualButton(is_bot_button, is_human_button)
                 .value_or(is_bot.value_or(false));

    is_timed = HandleDualButton(is_timed_button, is_not_timed_button)
                   .value_or(is_timed.value_or(false));

    for (const auto &box : {&width_box, &height_box}) {
      box->CheckFocus();
      box->HandleInput();
    }

    height_valid = height_box.TextIsValid();
    if (height_valid) {
      try {
        height = std::stoi(height_box.GetText());
      } catch (const std::invalid_argument &) {
      }
    } else {
      height = std::nullopt;
    }

    width_valid = width_box.TextIsValid();
    if (width_valid) {
      try {
        width = std::stoi(width_box.GetText());
      } catch (const std::invalid_argument &) {
      }
    } else {
      width = std::nullopt;
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

void View::LoadMaze(const maze_t &maze, const bool &fullScreen) {
  view_maze = ViewMaze(maze, fullScreen);
}

void View::LoadMaze(const maze_t &maze, const square &_start,
                    const square &_goal, const bool &fullScreen) {

  view_maze = ViewMaze(maze, fullScreen);
  this->start = _start;
  this->goal = _goal;
}

std::pair<ALGORITHM, bool> View::BotMode(optional<MazeSteps> solution,
                                         optional<MazeSteps> searched) {

  if (!view_maze.has_value() || !start.has_value() || !goal.has_value()) {
    throw std::runtime_error("View::BotMode: maze not loaded");
  }
  view_maze->Clear();

  Utils::PositionCalc calc(window.GetSize());
  constexpr int HORIZONTAL_OPTIONS_START = 65;

  const Vector2I DFS_POSITION = calc(HORIZONTAL_OPTIONS_START, 20);
  const Vector2I BFS_POSITION = calc(HORIZONTAL_OPTIONS_START, 40);
  const Vector2I GBFS_POSITION = calc(HORIZONTAL_OPTIONS_START, 60);
  const Vector2I A_STAR_POSITION = calc(HORIZONTAL_OPTIONS_START, 80);

  const Vector2I END_POSITION = calc(35, 80);

  Button dfs_button = Utils::DefaultButton("DFS", DFS_POSITION);
  Button bfs_button = Utils::DefaultButton("BFS", BFS_POSITION);
  Button gbfs_button = Utils::DefaultButton("GBFS", GBFS_POSITION);
  Button a_star_button = Utils::DefaultButton("A*", A_STAR_POSITION);

  Button end_button = Utils::DefaultButton("end", END_POSITION);

  uint frame_count = 0;

  square current = start.value();

  bool move_bot = true;

  while (!window.ShouldClose()) {

    if (current == goal.value()) {
      return {ALGORITHM::BFS, true};
    }

    move_bot = false;

    if (IsKeyPressed(KEY_RIGHT)) {
      view_maze->MoveRight(current);
      move_bot = true;

    } else if (IsKeyPressed(KEY_LEFT)) {
      view_maze->MoveLeft(current);
      move_bot = true;
    } else if (IsKeyPressed(KEY_UP)) {
      view_maze->MoveUp(current);
      move_bot = true;
    } else if (IsKeyPressed(KEY_DOWN)) {
      view_maze->MoveDown(current);
      move_bot = true;
    }

    // Drawing
    BeginDrawing();

    window.ClearBackground();
    background.Draw(0, 0);
    view_maze->Draw();
    DrawAll(dfs_button, bfs_button, gbfs_button, a_star_button, end_button);
    EndDrawing();

    frame_count++;
    if (move_bot && solution.has_value() && searched.has_value()) {

      if (searched->size() > 1) {
        auto current_bot = searched->front();

        searched->pop();
        auto next = searched->front();

        view_maze->DrawSearched(current_bot, next);
      } else if (solution->size() > 1) {

        auto current_bot = solution->front();
        solution->pop();
        auto next = solution->front();

        view_maze->DrawSolution(current_bot, next);
      } else {
      }
      continue;
    }

    if (dfs_button.IsClicked()) {
      std::cout << "dfs clicked\n";
      return {ALGORITHM::DFS, false};
    }
    if (bfs_button.IsClicked()) {
      std::cout << "bfs clicked\n";
      return {ALGORITHM::BFS, false};
    }
    if (gbfs_button.IsClicked()) {
      std::cout << "gbfs clicked\n";

      return {ALGORITHM::GBFS, false};
    }
    if (a_star_button.IsClicked()) {
      std::cout << "a* clicked\n";

      return {ALGORITHM::A_STAR, false};
    }
    if (end_button.IsClicked()) {
      std::cout << "end clicked\n";
      return {ALGORITHM::BFS, true};
    }
  }

  return {ALGORITHM::BFS, true};
}

optional<bool> View::HumanMode(const bool &timed) {
  if (timed) {
    return TimedHumanMode();
  }
  UntimedHumanMode();
  return std::nullopt;
}
void View::UntimedHumanMode() {

  if (!view_maze.has_value() || !start.has_value() || !goal.has_value()) {
    throw std::runtime_error("View::HumanMode: maze not loaded properly");
  }

  square current = start.value();

  while (!window.ShouldClose()) {

    if (current == goal.value()) {
      return;
    }

    if (IsKeyPressed(KEY_RIGHT)) {
      view_maze->MoveRight(current);
    } else if (IsKeyPressed(KEY_LEFT)) {
      view_maze->MoveLeft(current);
    } else if (IsKeyPressed(KEY_UP)) {
      view_maze->MoveUp(current);

    } else if (IsKeyPressed(KEY_DOWN)) {
      view_maze->MoveDown(current);
    }

    BeginDrawing();
    window.ClearBackground();
    background.Draw(0, 0);
    view_maze->Draw();
    EndDrawing();
  }
}
bool View::TimedHumanMode() {

  if (!view_maze.has_value() || !start.has_value() || !goal.has_value()) {
    throw std::runtime_error("View::HumanMode: maze not loaded properly");
  }

  Utils::PositionCalc calc(window.GetSize());

  std::chrono::minutes max_time(MAX_TIME);
  std::chrono::duration<double> remaining{};

  square current = start.value();

  rl::Text time_text = TextBuilder("Time remaining").FontSize(60).Color(WHITE);
  const Utils::Vector2I TIME_POSITION = calc(80, 20);

  while (!window.ShouldClose()) {

    remaining = max_time - std::chrono::duration<double>(GetTime());

    if (current == goal.value()) {
      return true;
    }
    if (remaining.count() <= 0) {
      return false;
    }

    if (IsKeyPressed(KEY_RIGHT)) {
      view_maze->MoveRight(current);
    } else if (IsKeyPressed(KEY_LEFT)) {
      view_maze->MoveLeft(current);
    } else if (IsKeyPressed(KEY_UP)) {
      view_maze->MoveUp(current);
    } else if (IsKeyPressed(KEY_DOWN)) {
      view_maze->MoveDown(current);
    }

    BeginDrawing();
    window.ClearBackground();
    background.Draw(0, 0);
    view_maze->Draw();

    time_text.Draw(TIME_POSITION);

    DrawText(std::to_string(static_cast<uint>(remaining.count())).c_str(),
             TIME_POSITION.x, TIME_POSITION.y + 100, 60, WHITE);

    EndDrawing();
  }
  return false;
}
