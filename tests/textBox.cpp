/*******************************************************************************************
 *
 *   raylib [text] example - Input Box
 *
 *   Example originally created with raylib 1.7, last time updated with
 *raylib 3.5
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an
 *OSI-certified, BSD-like license that allows static linking with closed source
 *software
 *
 *   Copyright (c) 2017-2023 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include <raylib-cpp.hpp>

#define MAX_INPUT_CHARS 900

namespace rl = raylib;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;

  // InitWindow(screenWidth, screenHeight, "raylib [text] example - input box");
  rl::Window window(screenWidth, screenHeight, "example input box");

  char name[MAX_INPUT_CHARS + 1] =
      "\0"; // NOTE: One extra space required for null terminator char '\0'
  int letterCount = 0;

  rl::Rectangle textBox = {screenWidth / 2.0f - 100, 180, 225, 50};
  bool mouseOnText = false;

  int framesCounter = 0;

  window.SetTargetFPS(30);
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    mouseOnText = CheckCollisionPointRec(GetMousePosition(), textBox);

    if (mouseOnText) {
      // Set the window's cursor to the I-Beam
      SetMouseCursor(MOUSE_CURSOR_IBEAM);

      // Get char pressed (unicode character) on the queue
      int key = GetCharPressed();

      // Check if more characters have been pressed on the same frame
      while (key > 0) {
        // NOTE: Only allow keys in range [32..125]
        if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
          name[letterCount] = (char)key;
          name[letterCount + 1] =
              '\0'; // Add null terminator at the end of the string.
          letterCount++;
        }

        key = GetCharPressed(); // Check next character in the queue
      }

      if (IsKeyPressed(KEY_BACKSPACE)) {
        letterCount--;
        if (letterCount < 0) {
          letterCount = 0;
        }
        name[letterCount] = '\0';
      }
    } else
      SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if (mouseOnText) {
      framesCounter++;
    } else {
      framesCounter = 0;
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    textBox.Draw(rl::Color::LightGray());

    DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

    // if (mouseOnText) {
    //   if (letterCount < MAX_INPUT_CHARS) {
    //     // Draw blinking underscore char
    //     if (((framesCounter / 20) % 2) == 0) {
    //       DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40),
    //                static_cast<int>(textBox.y) + 12, 40, MAROON);
    //     }
    //   } else {
    //     DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
    //   }
    // }

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  // CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
