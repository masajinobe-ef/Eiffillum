#include "raylib-cpp.hpp"

int main() {

  int screenWidth = 800;
  int screenHeight = 600;

  raylib::Color textColor = raylib::Color::Black();
  raylib::Window window(screenWidth, screenHeight, "Eiffillum");

  SetTargetFPS(144);

  while (!window.ShouldClose()) {

    BeginDrawing();
    {
    }

    EndDrawing();
  }

  return 0;
}
