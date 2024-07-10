#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <vector>
#include <string>
#include "TerminalColor.hpp"

/**
 * @class TerminalGame
 * Represents a terminal game engine.
 */
class Sprite {
public:

    std::vector<std::string> strArray; // The sprite's 2D array representation.
    std::vector<std::vector<TerminalColor>> colArray; // The sprite's 2D array representation
    int width, height; // Dimensions of the sprite.

    struct Point {
        int x, y; // Coordinates of the sprite's midpoint.
    };

    Point midPoint;
    Point pos;

    Sprite(const std::vector<std::string>& arr,
        const std::vector<std::vector<TerminalColor>>& colArray = {}
    );

    void move(int px, int py);
};

#endif // SPRITE_HPP