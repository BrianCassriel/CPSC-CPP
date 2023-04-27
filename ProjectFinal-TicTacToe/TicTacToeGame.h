//
// Created by Brian Cassriel on 4/6/23.
//

#ifndef TICTACTOE_TICTACTOEGAME_H
#define TICTACTOE_TICTACTOEGAME_H
using namespace std;

class TicTacToeGame {
public:
    TicTacToeGame();
    ~TicTacToeGame();
    void Play();

    int winner;
private:
    void InitializeGrid();
    void DisplayGrid();
    void DoUserTurn();
    void DoCpuTurn();
    bool CheckForGameEnd();
    bool SamePlayerInAllThreeSlots(int[3][2]);
    bool AllSlotsFull();
    void DisplayWinner() const;
    bool WillPlayFirstTurn();
    bool WillWin();
    bool WillBlock();
    void PlaceInRandomSlot();
    bool TryToPlayWinningMoveForPlayer(char);
    tuple<int, int> FindWinningSlotCoordsForPlayer(char);
    tuple<int, int> FindEmptySlotCoords(int (&)[3][2]);
    bool IsFoundOtherPlayer(int(&)[3][2], tuple<int, int>, char);

    char** gridPtrPtr;
    int winningConfigurations[8][3][2] = {
            { {0, 0}, {0, 1}, {0, 2} },
            { {1, 0}, {1, 1}, {1, 2} },
            { {2, 0}, {2, 1}, {2, 2} },
            { {0, 0}, {1, 0}, {2, 0} },
            { {0, 1}, {1, 1}, {2, 1} },
            { {0, 2}, {1, 2}, {2, 2} },
            { {0, 0}, {1, 1}, {2, 2} },
            { {0, 2}, {1, 1}, {2, 0}}
    };
    bool isFirstTurn;
};

#endif //TICTACTOE_TICTACTOEGAME_H
