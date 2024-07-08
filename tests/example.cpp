#include "../include/TerminalGame.hpp"
#include <iostream>
#include <string>

int main() {
    TerminalGame game;
    game.clearConsole();

    game.drawChar('D', 0, 0);

    std::string l;
    std::cin >> l;
    return 0;
}