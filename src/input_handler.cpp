#include "input_handler.h"
#include <raylib.h>

void HandleInput(std::string &text, bool &isTyping, bool &saveDialogOpen,
                 std::string &currentFilePath) {
  if (IsKeyPressed(KEY_ENTER)) {
    isTyping = !isTyping;
  }

  if (isTyping && !saveDialogOpen) {
    // Handle text input
    for (int key = 32; key < 128; key++) {
      if (IsKeyPressed(key)) {
        text += static_cast<char>(key);
      }
    }
    if (IsKeyPressed(KEY_BACKSPACE) && !text.empty()) {
      text.pop_back();
    }
    if (IsKeyPressed(KEY_S) && IsKeyDown(KEY_LEFT_CONTROL)) {
      saveDialogOpen = true;
      currentFilePath =
          "output"; // Reset the filename input for the save dialog
    }
  }
}
