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

#endif // TEXTRENDERER_HPP
