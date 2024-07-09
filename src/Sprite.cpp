#include "../include/TextRenderer.hpp"
#include "../include/Sprite.hpp"
#include <iostream>

Sprite::Sprite(const std::vector<std::string>& arr) {
    spriteArray = arr;

    width = arr.size();

    int height = 0;

    // Iterate through the vector
    for (const std::string& str : arr) {
        // Calculate the length of the current string
        int length = str.length();

        // Update maxLength if the current string length is greater
        if (length > height) {
            height = length;
        }
    }

    midPoint.x = width / 2;
    midPoint.y = height / 2;
}