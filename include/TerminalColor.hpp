#ifndef TERMINALCOLOR_HPP
#define TERMINALCOLOR_HPP

#include <string>

// Enum class for terminal colors
enum class TerminalColor {
    RESET = 0,      // Reset all attributes
    BLACK = 30,     // Black text
    RED,            // Red text
    GREEN,          // Green text
    YELLOW,         // Yellow text
    BLUE,           // Blue text
    MAGENTA,        // Magenta text
    CYAN,           // Cyan text
    WHUTE           // White text
};

/**
 * @brief This function returns the ANSI escape sequence for the given terminal color.
 *
 * @param color The enum value representing the desired terminal color.
 *
 * @return A string containing the ANSI escape sequence for the specified color.
 *         The escape sequence can be used to change the text color in a terminal.
 *         For example, "\033[31m" will set the text color to red.
 *         To reset the color, use the TerminalColor::Reset enum value.
 *
 * @note The returned string includes the necessary escape characters and color code.
 *       It is recommended to use the applyColor() function for easier color application.
 */
std::string getColorCode(TerminalColor color);

/**
 * @brief Applies the specified terminal color to the given string.
 *
 * This function takes a TerminalColor enum value and a string as input.
 * It returns a new string with the ANSI escape sequence for the specified color
 * prepended to the input string, and the reset color code appended at the end.
 *
 * @param color The enum value representing the desired terminal color.
 * @param str   The input string to which the color will be applied.
 *
 * @return A string with the specified color applied to the input string.
 *         The returned string can be displayed in a terminal to change the text color.
 *
 * @note The returned string includes the necessary escape characters and color codes.
 *       To reset the color, use the TerminalColor::Reset enum value.
 *
 * @example
 * std::string coloredText = applyColor(TerminalColor::Red, "This is red text");
 * std::cout << coloredText << std::endl;
 * // Output: "\033[31mThis is red text\033[0m"
 */
std::string applyColor(TerminalColor color, const std::string str);

#endif // TERMINALCOLOR_HPP