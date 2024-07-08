#include "../include/TerminalGame.hpp"
#include <iostream>
#include <cstdlib>

TerminalGame::TerminalGame() {

}

// Below is the base engine definiton.

void BaseEngine::clearConsole() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void BaseEngine::run() {
    std::cout << "Game loop running..." << std::endl;
    // Game loop implementation here
}

void BaseEngine::drawChar(char c, short x, short y, bool useOld) {
    if (!useOld) {
        setCursorPosition(std::max(0, x - 1), std::max(0, y - 1));
    }
    else {
        for (int i = 0; i < y; i++) {
            std::cout << std::endl;
        }
        for (int i = 0; i < x; i++) {
            std::cout << ' ';
        }
    }
    std::cout << c;
}

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

std::pair<short, short> BaseEngine::getTerminalSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return { rows, cols };
}

void BaseEngine::setTerminalSize(int cols, int rows) {
    SMALL_RECT rect = { 0, 0, (short)(cols - 1), (short)(rows - 1) };
    COORD coord = { (short)(cols), (short)(rows) };
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);
}

void BaseEngine::setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, position);
}

#else
#include <sys/ioctl.h>
#include <unistd.h>
#include <term.h>

std::pair<short, short> BaseEngine::getTerminalSize() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return { w.ws_row, w.ws_col };
}

void BaseEngine::setTerminalSize(int cols, int rows) {
    struct winsize w;
    w.ws_col = cols;
    w.ws_row = rows;
    ioctl(STDOUT_FILENO, TIOCSWINSZ, &w);
}

void BaseEngine::setCursorPosition(int x, int y) {
    if (!cur_term) {
        int result;
        setupterm(NULL, STDOUT_FILENO, &result);
        if (result <= 0) return;
    }
    putp(tparm(cursor_address, y, x));
}

#endif