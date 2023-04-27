//
// Created by Brian Cassriel on 4/6/23.
//
#include <iostream>
#include <tuple>
#include <random>

#include "TicTacToeGame.h"
using namespace std;

TicTacToeGame::TicTacToeGame() {
    gridPtrPtr = new char* [3];
    gridPtrPtr[0] = new char[3];
    gridPtrPtr[1] = new char[3];
    gridPtrPtr[2] = new char[3];
    winner = -1;
    InitializeGrid();
    isFirstTurn = true;
}

TicTacToeGame::~TicTacToeGame() {
    for (int i = 0; i < 3; i++) {
        delete[] gridPtrPtr[i];
    }
    delete[] gridPtrPtr;
}

void TicTacToeGame::Play() {
    while (winner == -1) {
        DisplayGrid();
        DoUserTurn();
        if (CheckForGameEnd())
            break;
        DisplayGrid();
        DoCpuTurn();
        CheckForGameEnd();
    }
    DisplayGrid();
    DisplayWinner();
}

void TicTacToeGame::DisplayWinner() const {
    cout << "Winner: ";
    switch (winner) {
        case 0:
            cout << "Tie";
            break;
        case 1:
            cout << "User";
            break;
        case 2:
            cout << "CPU";
            break;
        default:
            cout << "None. Something went wrong...";
    }
    cout << endl;
}

void TicTacToeGame::DoCpuTurn() {
    if (WillPlayFirstTurn())
        return;
    if (WillWin())
        return;
    if (WillBlock())
        return;
    PlaceInRandomSlot();
}

// BEGIN CODE FOR CPU AI

void TicTacToeGame::PlaceInRandomSlot() {
    random_device randomDevice;
    default_random_engine randomNumberGenerator(randomDevice());
    int row;
    int column;

    uniform_int_distribution<int> randInt(0, 2);
    while (true) {
        row = randInt(randomNumberGenerator);
        column = randInt(randomNumberGenerator);
        if (gridPtrPtr[row][column] == '~' || AllSlotsFull())
            break;
    }
    if (!AllSlotsFull()) {
        gridPtrPtr[row][column] = 'O';
        cout << "CPU used a random slot" << endl;
    }
}

bool TicTacToeGame::WillPlayFirstTurn() {
    if (isFirstTurn) {
        isFirstTurn = false;
        if (gridPtrPtr[1][1] == '~') {
            cout << "CPU played first turn" << endl;
            gridPtrPtr[1][1] = 'O';
            return true;
        }
    }
    return false;
}

bool TicTacToeGame::WillWin() {
    return TryToPlayWinningMoveForPlayer('O');
}

bool TicTacToeGame::WillBlock() {
    return TryToPlayWinningMoveForPlayer('X');
}

bool TicTacToeGame::TryToPlayWinningMoveForPlayer(char ourMarkerType) {
    int row = 0;
    int column = 0;
    tie(row, column) = FindWinningSlotCoordsForPlayer(ourMarkerType);
    if (row != -1 && column != -1) {
        gridPtrPtr[row][column] = 'O';
        return true;
    }
    return false;
}

tuple<int, int> TicTacToeGame::FindWinningSlotCoordsForPlayer(char ourMarkerType) {
    tuple<int, int> bestCoords;
    tuple<int, int> emptySlotCoords;

    for (int (&winningConfiguration)[3][2] : winningConfigurations) {
        emptySlotCoords = FindEmptySlotCoords(winningConfiguration);

        if (emptySlotCoords == make_tuple(-1, -1) || IsFoundOtherPlayer(winningConfiguration, emptySlotCoords, ourMarkerType))
            bestCoords = make_tuple(-1, -1);
        else
            bestCoords = emptySlotCoords;

        if (bestCoords != make_tuple(-1, -1)) {
            cout << "CPU won or blocked" << endl;
            return bestCoords;
        }
    }
    return make_tuple(-1, -1);
}

tuple<int, int> TicTacToeGame::FindEmptySlotCoords(int (&winningConfiguration)[3][2]) {
    for (int (&slot)[2] : winningConfiguration) {
        if (gridPtrPtr[slot[0]][slot[1]] == '~')
            return make_tuple(slot[0], slot[1]);
    }
    return make_tuple(-1, -1);
}

bool TicTacToeGame::IsFoundOtherPlayer(int (&winningConfiguration)[3][2], tuple<int, int> emptySlotCoords, char ourMarkerType) {
    for (int (&slot)[2] : winningConfiguration) {
        if (emptySlotCoords != make_tuple(slot[0], slot[1])
            && gridPtrPtr[slot[0]][slot[1]] != ourMarkerType)
            return true;
    }
    return false;
}

// END CODE FOR CPU AI

bool TicTacToeGame::CheckForGameEnd() {
    for (auto &winningConfiguration : winningConfigurations) {
        if (SamePlayerInAllThreeSlots(winningConfiguration)) {
            if (gridPtrPtr[winningConfiguration[0][0]][winningConfiguration[0][1]] == 'X')
                winner = 1;
            else
                winner = 2;
        }
    }

    if (winner == -1 && AllSlotsFull()) {
        winner = 0;
    }

    if (winner != -1)
        return true;
    return false;
}

bool TicTacToeGame::AllSlotsFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gridPtrPtr[i][j] == '~')
                return false;
        }
    }
    return true;
}

bool TicTacToeGame::SamePlayerInAllThreeSlots(int winningConfiguration[3][2]) {
    if (gridPtrPtr[winningConfiguration[0][0]][winningConfiguration[0][1]] == '~')
        return false;
    return     gridPtrPtr[winningConfiguration[0][0]][winningConfiguration[0][1]]
            == gridPtrPtr[winningConfiguration[1][0]][winningConfiguration[1][1]]
            && gridPtrPtr[winningConfiguration[1][0]][winningConfiguration[1][1]]
            == gridPtrPtr[winningConfiguration[2][0]][winningConfiguration[2][1]];
}

void TicTacToeGame::InitializeGrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gridPtrPtr[i][j] = '~';
        }
    }
}

void TicTacToeGame::DisplayGrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << gridPtrPtr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void TicTacToeGame::DoUserTurn() {
    int rowNum;
    int columnNum;

    while (true) {
        cout << "Please enter a row: ";
        while (true) {
            cin >> rowNum;
            if (rowNum >= 0 && rowNum < 3)
                break;
            else
                cout << "Invalid row, please try again: ";
        }

        cout << "Please enter a column: ";
        while (true) {
            cin >> columnNum;
            if (columnNum >= 0 && columnNum < 3)
                break;
            else
                cout << "Invalid column, please try again: ";
        }

        if (gridPtrPtr[rowNum][columnNum] == '~')
            break;
        else
            cout << "That grid spot is already taken. Please try again." << endl;
    }

    gridPtrPtr[rowNum][columnNum] = 'X';
    cout << endl;
}



