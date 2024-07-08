#include "../include/TerminalGame.hpp"
#include <iostream>
#include <string>

int main() {
    TerminalGame game;
    game.clearConsole();

    game.drawChar('D', 0, 0);
    game.drawChar('A', 1, 0);
    game.drawChar('B', 23, 0); // trying to go backwards
    game.drawChar('O', 7, 23);

    std::string l;
    std::cin >> l;
    return 0;
}