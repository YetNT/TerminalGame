#include "../include/TerminalGame.hpp"
#include <iostream>
#include <string>

int main() {
    TerminalGame game;
    game.clearConsole();

    std::string co;
    std::cout << "Holy fuck it works???";
    std::cin >> co;
    std::cout << co << std::endl;
    return 0;
}