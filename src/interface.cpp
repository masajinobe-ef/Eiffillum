#include "interface.h"
#include <raylib.h>

void DrawInterface(const Font &customFont, const std::string &text,
                   bool saveDialogOpen, const std::string &currentFilePath) {
  ClearBackground(BLACK);
  DrawRectangle(0, 0, 800, 50, DARKGRAY);

  if (saveDialogOpen) {
    DrawTextEx(customFont, "Saving file: Type the file name and press Enter...",
               Vector2{10, 10}, customFont.baseSize, 1, WHITE);
    DrawTextEx(customFont, currentFilePath.c_str(), Vector2{10, 60},
               customFont.baseSize, 1, WHITE);
  } else {
    DrawTextEx(customFont, text.c_str(), Vector2{10, 60}, customFont.baseSize,
               1, WHITE);
    DrawTextEx(customFont, "Press Enter to toggle typing mode",
               Vector2{10, 550}, customFont.baseSize, 1, WHITE);
    DrawTextEx(customFont, "Press Ctrl+S to save", Vector2{10, 570},
               customFont.baseSize, 1, WHITE);
  }
}
