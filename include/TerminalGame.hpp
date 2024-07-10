#ifndef BASEENGINE_HPP
#define BASEENGINE_HPP


#include "TextRenderer.hpp"

#include <utility>
#include <chrono>
#include <thread>

/**
 * @class BaseEngine
 * Represents a terminal game engine.
 */
class BaseEngine {
public:
    BaseEngine() = default; // Default constructor;
    TextRenderer renderer;
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
    void oldDrawChar(char c, short x, short y);

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
    * @brief Waits for the specified number of milliseconds.
    *
    * This function suspends the execution of the current thread for the specified number of milliseconds.
    * It uses the std::this_thread::sleep_for function from the <chrono> library to achieve this.
    *
    * @param milliseconds The number of milliseconds to wait.
    *
    * @return void
    */
    void wait(int milliseconds);

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