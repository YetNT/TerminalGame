#include "../include/TextRenderer.hpp"
#include <iostream>

void TextRenderer::drawChar(char c, short x, short y) {
    // Flush the buffer before setting the cursor position
    std::cout.flush();

    setCursorPosition(std::max(0, static_cast<int>(x)), std::max(0, static_cast<int>(y)));
    std::cout << c;
    std::cout.flush(); // Ensure output is immediate
}

inline void TextRenderer::addSprite(const Sprite& sprite) {
    sprites.push_back(sprite);
}

inline void TextRenderer::addSprites(const std::vector<Sprite>& spritesToAdd) {
    sprites.insert(sprites.end(), spritesToAdd.begin(), spritesToAdd.end());
}

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>


void TextRenderer::setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, position);
}

#else
#include <sys/ioctl.h>
#include <unistd.h>
#include <term.h>


void TextRenderer::setCursorPosition(int x, int y) {
    if (!cur_term) {
        int result;
        setupterm(NULL, STDOUT_FILENO, &result);
        if (result <= 0) return;
}
    putp(tparm(cursor_address, y, x));
}

#endif