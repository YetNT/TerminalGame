#include "../include/TerminalGame.hpp"
#include "../include/TerminalColor.hpp"
#include <iostream>
#include <string>

int main() {
    TerminalGame game;
    game.clearConsole();

    Sprite p({ "AB", "CD" }, { { TerminalColor::RED, TerminalColor::CYAN}, {TerminalColor::MAGENTA, TerminalColor::YELLOW} });

    game.renderer.addSprite(p);

    int x = 1;
    while (x != 0) {
        game.renderer.renderFrame();
        std::cin >> x;
        p.move(x, 0);
    }

    std::string e;
    std::cin >> e;
    return 0;
}