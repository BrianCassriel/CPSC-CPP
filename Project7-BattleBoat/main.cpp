/// @file main.cpp
/// @brief main function file for Game
/// @author cassriel@chapman.edu
/// CPSC 298-10 Colloquium: Programming in C++

#include <iostream>

#include "Game.h"

int main()
{
    bool bPlay = true;
    Game game;

    while (bPlay) {
        game.play();

        std::cout << std::endl;
        char cPlay = 'n';
        std::cout << "Play another game? (y/n)" << std::endl;
        std::cin >> cPlay;
        if (cPlay == 'n')
        {
            bPlay = false;
        }
    }

    return 0;
}
