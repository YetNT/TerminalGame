#ifndef TEXTRENDERER_HPP
#define TEXTRENDERER_HPP

#include "Sprite.hpp"


/**
 * @class TextRenderer
 * Renders Text to the terminal.
 */
class TextRenderer {
public:
    std::vector<Sprite>& sprites;

    enum class TerminalColor {
        Reset = 0,      // Reset all attributes
        Black = 30,     // Black text
        Red,            // Red text
        Green,          // Green text
        Yellow,         // Yellow text
        Blue,           // Blue text
        Magenta,        // Magenta text
        Cyan,           // Cyan text
        White           // White text
    };

    void drawChar(char c, short x, short y);


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
    void addSprite(const Sprite& sprite);

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
    void addSprites(const std::vector<Sprite>& spritesToAdd);
};

#endif // TEXTRENDERER_HPP