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
    struct Point {
        int x, y; // Coordinates of the sprite's midpoint.
    };

    Point pos;
    Point midPoint;

    std::vector<std::string> strArray; // The sprite's 2D array representation.
    std::vector<std::vector<TerminalColor>> colArray; // The sprite's 2D array representation
    int width, height; // Dimensions of the sprite.

    Sprite(const std::vector<std::string>& arr,
        Point position,
        const std::vector<std::vector<TerminalColor>>& colArray = {}
    );

    void move(int px, int py);
};

#endif // SPRITE_HPP