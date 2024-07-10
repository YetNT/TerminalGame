#include "TerminalColor.hpp"

// Function to get the ANSI escape code string for the given color
std::string getColorCode(TerminalColor color) {
    return "\033[" + std::to_string(static_cast<int>(color)) + "m";
}

std::string applyColor(TerminalColor color, const std::string str) {
    return getColorCode(color) + str + "\033[0m";
}