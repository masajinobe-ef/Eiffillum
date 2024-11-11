#ifndef INTERFACE_H
#define INTERFACE_H

#include <raylib.h>
#include <string>

void DrawInterface(const Font &customFont, const std::string &text,
                   bool saveDialogOpen, const std::string &currentFilePath);

#endif // INTERFACE_H
