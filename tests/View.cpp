#include "./View.hpp"
#include "./Button.hpp"

void View::run() {
  Button but;
  Button but2;

  auto count = 0;
  while (!sWindow().ShouldClose()) {

    BeginDrawing();

    but.Draw(100, 100);
    but2.Draw(300, 300);

    count++;
    if (count == 3000) {
      break;
    }
    EndDrawing();
  }
}
