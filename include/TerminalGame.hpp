#ifndef BASEENGINE_HPP
#define BASEENGINE_HPP


#include "TextRenderer.hpp"
#include "Sprite.hpp"

#include <utility>
#include <chrono>
#include <thread>

/**
 * @class BaseEngine
 * Represents a terminal game engine.
 */
class BaseEngine {
protected:
    /**
    * @brief Draws a sprite to the terminal.
    *
    * This function takes a sprite object as input and draws it to the terminal at its current position.
    * The sprite's appearance and color are determined by the properties of the provided Sprite object.
    *
    * @param sprite A reference to the Sprite object to be drawn. The sprite's position, appearance,
    *                and color are determined by the properties of this object.
    *
    * @return void
    */
    void drawSprite(const Sprite& sprite);

    void drawSprites();
public:
    struct TerminalSize {
        int x;
        int y;
    };

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
    TerminalSize getTerminalSize();

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

    /**
    * @brief Adds a single sprite to the renderer.
    *
    * This function adds the provided sprite to the internal list of sprites to be rendered.
    * The sprite is not actually drawn to the terminal until the draw() function is called.
    *
    * @param sprite A reference to the sprite to be added. The sprite's position and appearance
    *               are determined by the properties of this object.
    *
    * @return void
    */
    void addSprite(Sprite* pointerToSprite);

    /**
    * @brief Adds a collection of sprites to the renderer.
    *
    * This function adds the provided collection of sprites to the internal list of sprites to be rendered.
    * The sprites are not actually drawn to the terminal until the draw() function is called.
    *
    * @param spritesToAdd A reference to the vector of sprites to be added.
    *
    * @return void
    */
    void addSprites(std::vector<Sprite*> pointerToSpritesToAdd);

    /**
    * @brief Renders the current state of all sprites to the terminal.
    *
    * This function iterates through the internal list of sprites, retrieves their position, appearance,
    * and color information, and then draws them to the terminal using the appropriate character and color
    * codes. The rendering process is optimized to minimize the number of console output operations,
    * ensuring smooth and efficient rendering.
    *
    * @return void
    */
    void renderFrame();

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