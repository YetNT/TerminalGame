#ifndef BASEENGINE_HPP
#define BASEENGINE_HPP

#include <utility>

/**
 * @class BaseEngine
 * Represents a terminal game engine.
 */
class BaseEngine {
public:
    void run();
    /**
    * Clears the console screen.
    * @memberof TerminalGame
    */
    void clearConsole();

    /**
    * Draws a character at the specified position.
    * @param x The x-coordinate.
    * @param y The y-coordinate.
    * @param ch The character to draw.
    * @param useOld If true, the old character draw function will be used.
    */
    void drawChar(char c, short x, short y, bool useOld = false);

    /**
    * Gets the current terminal size.
    * @return A pair representing the number of rows and columns. <rows, cols>
    */
    std::pair<short, short> getTerminalSize();

    /**
     * Sets the terminal size.
     * @param cols The number of columns.
     * @param rows The number of rows.
     */
    void setTerminalSize(int cols, int rows);

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

#endif // BASEENGINE_HPP

#ifndef TERMINALGAME_HPP
#define TERMINALGAME_HPP

/**
 * @class TerminalGame
 * Represents a terminal game engine.
 */
class TerminalGame : public BaseEngine {
public:
    TerminalGame();
};

#endif // TERMINALGAME_HPP