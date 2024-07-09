#include "../include/TerminalGame.hpp"
#include <iostream>
#include <string>

int main() {
    TerminalGame game;
    game.clearConsole();

    // std::pair<short, short> a = game.getTerminalSize();

    bool ld = false;
    struct coords {
        int x;
        int y;
    };
    coords place = { 0, 0 };
    for (int r = 0;r <= 40; r++) {
        if (ld) {
            place.x++;
            game.renderer.drawChar('O', place.x, place.y);
        }
        else {
            place.y++;
            game.renderer.drawChar('O', place.x, place.y);
        }
        if (r % 10 == 0) ld = !ld;
        game.wait(100);
    }

    std::string e;
    std::cin >> e;
    return 0;
}