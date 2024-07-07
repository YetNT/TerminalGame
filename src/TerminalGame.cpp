#include "../include/TerminalGame.hpp"
#include <iostream>
#include <cstdlib>

void TerminalGame::run() {
    std::cout << "Game loop running..." << std::endl;
    // Game loop implementation here
}

void TerminalGame::clearConsole() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
