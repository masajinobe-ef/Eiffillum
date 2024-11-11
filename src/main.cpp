#include "file_manager.h"
#include "input_handler.h"
#include "interface.h"
#include "raylib-cpp.hpp"
#include <string>

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  raylib::Window window(screenWidth, screenHeight, "Eiffillum");
  SetTargetFPS(144);

  std::string text = "";
  bool isTyping = false;
  bool saveDialogOpen = false;
  std::string currentFilePath = "";

  // Load custom font
  Font customFont = LoadFont("resources/fonts/regular.ttf");

  while (!window.ShouldClose()) {
    if (IsWindowFocused()) {
      HandleInput(text, isTyping, saveDialogOpen, currentFilePath);
    }

    BeginDrawing();
    {
      DrawInterface(customFont, text, saveDialogOpen, currentFilePath);

      if (saveDialogOpen) {
        // File name typing
        for (int key = 32; key < 128; key++) {
          if (IsKeyPressed(key)) {
            currentFilePath += static_cast<char>(key);
          }
        }
        if (IsKeyPressed(KEY_BACKSPACE) && !currentFilePath.empty()) {
          currentFilePath.pop_back();
        }

        // Save the file when pressing Enter
        if (IsKeyPressed(KEY_ENTER) && !currentFilePath.empty()) {
          SaveFile(currentFilePath, text);
          saveDialogOpen = false; // Close the dialog after saving
        }
      }
    }
    EndDrawing();
  }

  UnloadFont(customFont);
  return 0;
}
