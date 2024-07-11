#include "../include/TextRenderer.hpp"
#include "../include/Sprite.hpp"
#include <iostream>

Sprite::Sprite(const std::vector<std::string>& arr, Point position, const std::vector<std::vector<TerminalColor>>& colArray)
    : strArray(arr), colArray(colArray), width(arr.empty() ? 0 : arr[0].size()), height(arr.size()) {

    // If colArray is empty, initialize it with default colors (e.g., TerminalColor::Reset)
    if (this->colArray.empty()) {
        this->colArray.resize(height, std::vector<TerminalColor>(width, TerminalColor::RESET));
    }
    else {
        // Ensure colArray has the same dimensions as strArray
        if (static_cast<int>(this->colArray.size()) != height || (height > 0 && static_cast<int>(this->colArray[0].size()) != width)) {
            throw std::invalid_argument("Color array dimensions must match string array dimensions.");
        }
    }

    // Calculate the midpoint of the sprite
    midPoint.x = 0;
    midPoint.y = 0;

    pos.x = position.x;
    pos.y = position.y;
}

void Sprite::move(int px, int py) {
    pos.x += px;
    pos.y += py;
}