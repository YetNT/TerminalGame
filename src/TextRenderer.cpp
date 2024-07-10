#include "../include/TextRenderer.hpp"
#include "../include/TerminalColor.hpp"
#include <iostream>

void TextRenderer::drawChar(char c, short x, short y, TerminalColor col) {
    // Flush the buffer before setting the cursor position
    std::cout.flush();

    std::string str(1, c);

    setCursorPosition(std::max(0, static_cast<int>(x)), std::max(0, static_cast<int>(y)));
    std::cout << applyColor(col, str);
    std::cout.flush(); // Ensure output is immediate
}

void TextRenderer::addSprite(const Sprite& sprite) {
    sprites.push_back(sprite);
}

void TextRenderer::addSprites(const std::vector<Sprite>& spritesToAdd) {
    sprites.insert(sprites.end(), spritesToAdd.begin(), spritesToAdd.end());
}

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>


void TextRenderer::setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, position);
}

void TextRenderer::drawSprite(const Sprite& sprite) {
    int startX = sprite.midPoint.x;
    int y = sprite.midPoint.y;

    for (int outerVectorIndex = 0; outerVectorIndex < (int)sprite.strArray.size(); ++outerVectorIndex) {

        std::string str = sprite.strArray[outerVectorIndex];
        std::vector<TerminalColor> colVector = sprite.colArray[outerVectorIndex];
        int x = startX; // Reset x position for each row

        for (int innerVectorIndex = 0; innerVectorIndex < (int)str.size(); ++innerVectorIndex) {
            char c = str[innerVectorIndex];
            TerminalColor col = (innerVectorIndex >= (int)colVector.size()) ? TerminalColor::RESET : colVector[innerVectorIndex];
            drawChar(c, x, y, col);
            ++x;
        }
        ++y;
    }
}

void TextRenderer::drawSprites() {
    for (const auto& sprite : sprites) {
        drawSprite(sprite);
    }
}

void TextRenderer::renderFrame() {
    drawSprites();
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