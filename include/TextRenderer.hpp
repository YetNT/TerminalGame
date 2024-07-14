#ifndef TEXTRENDERER_HPP
#define TEXTRENDERER_HPP

#include "Sprite.hpp"
#include "TerminalColor.hpp"
#include <vector>

/**
 * @class TextRenderer
 * Renders Text to the terminal.
 */
class TextRenderer {
protected:

public:
    // No need for a constructor that initializes sprites; it's now an internal member
    std::vector<Sprite*> spritePointers; // Rendered from [0] to [>0], so element 1 will appear over element 0 if they overlap.

    void drawChar(char c, short x, short y, TerminalColor col = TerminalColor::RESET);

    /**
    * @brief Sets the cursor position in the console.
    *
    * This function sets the cursor position to the specified coordinates (x, y) in the console.
    * The top-left corner of the console is considered as the origin (0, 0).
    *
    * @param x The x-coordinate of the new cursor position.
    * @param y The y-coordinate of the new cursor position.
    *
    * @return void
    */
    void setCursorPosition(int x, int y);

};

#endif // TEXTRENDERER_HPP
