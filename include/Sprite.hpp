#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <vector>
#include <string>

/**
 * @class TerminalGame
 * Represents a terminal game engine.
 */
class Sprite {
public:
    std::vector<std::string> spriteArray; // The sprite's 2D array representation.
    int width, height; // Dimensions of the sprite.

    struct midPoint {
        int x, y; // Coordinates of the sprite's midpoint.
    } midPoint;

    Sprite(const std::vector<std::string>& arr);
};

#endif // SPRITE_HPP