#include <iostream>
#include "TicTacToeGame.h"

int main() {
    TicTacToeGame* gamePtr = new TicTacToeGame();
    gamePtr->Play();
    delete gamePtr;
    return 0;
}
