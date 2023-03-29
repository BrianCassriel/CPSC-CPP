/// @file Game.cpp
/// @brief Implementation file for Game class
/// @author cassriel@chapman.edu
/// CPSC 298-10 Colloquium: Programming in C++

#include <iostream>
#include <tuple>    // defines std::tuple, std::tie
#include <cmath>    // defines std::abs
#include <random>   // defines random number generation functions

#include "Game.h"   // defines Game class

// #define TEST  // macro to enable test mode functionality (not used during ordinary gameplay)
// #define DIAG  // macro to enable diagnostic output (not used during ordinary gameplay)

Game::Game() : m_nGridRows(k_nGridRowsDefault), m_nGridColumns(k_nGridColumnsDefault), m_iRowBoat(0), m_iColumnBoat(0), m_nTorpedoes(k_nMaxTorpedoes)
{
    initializeGrid();
}

// Implementation notes on Game::initializeGrid
//
// When the coordinate grid is initialized, all elements of the
// the two dimensional array a_cGrid are set to contain the
// wave character, a tilde: '~'.
//
// When rendered by displayGrid, the initialized grid appears
// as follows:
//
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
void Game::initializeGrid()
{
    for (int iRow = 0; iRow < this->m_nGridRows; iRow++)
    {
        for (int iColumn = 0; iColumn < this->m_nGridColumns; iColumn++)
        {
            this->a_cGrid[iRow][iColumn] = '~';
        }
    }
}

// Implementation notes on Game::displayGrid
//
// The displayGrid method shows every character within the two-dimensional
// character array a_cGrid. It places a bar on either side of the character
// to make the grid easier for the user to see.
//
// The grid initially contains only tilde characters, '~', ("waves"):
//
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
//
// Later it may contain asterisks ('*'), "torpedo explosions", the symbol for the target boat, 'V',
// or an 'X' to indicate the target boat was sunk at that location.
//
// The display of the target boat requires special handling.
//
// Assume that a the target boat is placed in position 2, 0 and a 'V' character is inserted at
// that location.
//
// During gameplay, the position of the target boat remains hidden and an wave (tilde character, '~')
// is rendered in that location. The displayGrid must "overwrite" the V character when parameter
// bShowboat is false.
//
// When bShowboat is false, the grid is rendered as follows. Note that location 2, 0 contains a '~'
// character.
//
// |*|~|~|~|~|
// |~|~|~|~|~|
// |~|*|*|~|~|
// |*|*|~|*|~|
//
// When the player has expended all of their torpedoes (and lost the game), the location of the
// target boat is rendered with a 'V' character.
//
// When bShowboat is true, the grid is rendered as follows: note that location 2,0 contains a
// 'V' character, indicating the position of the target boat.
// |*|~|*|*|~|
// |~|~|~|*|*|
// |V|*|*|~|~|
// |*|*|~|*|~|
void Game::displayGrid(bool bShowBoat) {
    for (int iRow = 0; iRow < this->m_nGridRows; iRow++)
    {
        std::cout << "|";
        for (int iColumn = 0; iColumn < this->m_nGridColumns; iColumn++)
        {
            if ('V' == this->a_cGrid[iRow][iColumn])
            {
                if (bShowBoat)
                {
                    std::cout << "V" << "|";
                }
                else
                {
                    std::cout << "~" << "|";
                }
            }
            else
            {
                std::cout << this->a_cGrid[iRow][iColumn] << "|";
            }
        }
        std::cout << std::endl;
    }
}

// Implementation notes on Game::fireTorpedo
//
// The user is prompted to enter a row, column location that is the aimpoint
// for their torpedo by calling the promptForGridCoord member function.
//
// Prior to firing the first torpedo, the game grid would be rendered as
// shown below (all elements of the a_cGrid contain '~' characters.)
//
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
//
//
// After the torpedo is "fired" an asterisk character ('*') is rendered
// at the location entered by the user. In the figure below, the
// torpedo was fired at location 2, 1:
//
// |~|~|~|~|~|
// |~|*|~|~|~|
// |~|~|~|~|~|
// |~|~|~|~|~|
//
// Game::fireTorpedo inserts an asterisk at the torpedo aimpoint location
// in the a_cGrid two-dimensional array. It also decrements the
// remaining number of torpedoes member variable this->m_nTorpedoes.
std::tuple<int, int>  Game::fireTorpedo()
{
    int iRow = 0;
    int iColumn = 0;

    this->m_nTorpedoes--;

    std::cout << "Enter grid Coordinates (row, column) of torpedo target grid square" << std::endl;
    std::tie(iRow, iColumn) = promptForGridCoord();
    this->a_cGrid[iRow][iColumn] = '*';

    std::tuple<int, int> tupleTorpedoCoord(iRow, iColumn);
    return tupleTorpedoCoord;
}

void Game::placeBoatRandomly()
{
    std::random_device randomDevice;
    std::default_random_engine randomNumberGenerator(randomDevice());

    std::uniform_int_distribution<int> uniformIntegerDistributionRows(0, (this->m_nGridRows - 1));
    std::uniform_int_distribution<int> uniformIntegerDistributionColumns(0, (this->m_nGridColumns - 1));

    this->m_iRowBoat = uniformIntegerDistributionRows(randomNumberGenerator);
    this->m_iColumnBoat = uniformIntegerDistributionColumns(randomNumberGenerator);

    this->a_cGrid[this->m_iRowBoat][this->m_iColumnBoat] = 'V';

#if defined(DIAG)
    std::cout << "DIAG: Boat location (Row/Column): " << this->m_iRowBoat << "; " << this->m_iColumnBoat << std::endl;
#endif
}

// Implementation notes on Game::placeBoat
// Game::placeBoat is used for testing purposes only. During gameplay,  Game::placeBoatRandomly()
// is used instead.
void Game::placeBoat()
{
    int iRow = 0;
    int iColumn = 0;

    std::cout << "Enter the grid square coordinates  (row, column) of target boat" << std::endl;

    std::tie(iRow, iColumn) = promptForGridCoord();
    this->a_cGrid[iRow][iColumn] = 'V';
    this->m_iRowBoat = iRow;
    this->m_iColumnBoat = iColumn;
}

bool Game::isOnTarget(int iRow, int iColumn)
{
    bool bHit = false;
    if ((iRow == this->m_iRowBoat) && (iColumn == this->m_iColumnBoat))
    {
        bHit = true;
    }

    return bHit;
}

// Implementation notes on Game::isCloseToTarget
//
// The Game::isCloseToTarget returns true if the value of the iRow and iColumn
// parameters are in a any of the eight grid squares surrounding the
// location of the target boat, shown with a V.
//
// |~|1|2|3|~|
// |~|4|V|5|~|
// |~|6|7|8|~|
// |~|~|~|~|~|
//
// If iRow and iColumn are identical to the location of the target boat, 'V',
// Game::isCloseToTarget should also return true. (Hitting it is pretty close!)
// The Game::isOnTarget member functions handles the case where the target is
// hit; nonetheless, it's OK for Game::isCloseToTarget to report that location
// as close.
//
// One way to determine "closeness" is to check if iRow and iColumn and at most 1
// square away from the location of the target boat, given by this->m_iRowBoat and
// this->m_iColumnBoat. By at most one is meant 0 or 1 (as might be expressed by
// an expression involving <=1.)
bool Game::isCloseToTarget(int iRow, int iColumn)
{
    bool bClose = false;
    if ((std::abs(iRow - this->m_iRowBoat) <= 1) && (std::abs(iColumn - this->m_iColumnBoat) <= 1))
    {
        bClose = true;
    }

    return bClose;
}

void Game::showSunk()
{
    this->a_cGrid[this->m_iRowBoat][this->m_iColumnBoat] = 'X';
}

std::tuple<int, int> Game::promptForGridCoord() // Added extra check so coords outside of the grid aren't selected
{
    int iRow = -1;
    int iColumn = -1;

    while (iRow < 0 || iColumn < 0) {
        std::cout << "Please enter grid row number: ";
        std::cin >> iRow;

        std::cout << "Please enter grid column number: ";
        std::cin >> iColumn;

        if (iRow >= this->m_nGridRows) {
            std::cout << "Invalid row number. Must be a positive number less than " << this->m_nGridRows << "."
                      << std::endl;
            iRow = -1;
        }
        if (iColumn >= this->m_nGridColumns) {
            std::cout << "Invalid column number. Must be a positive number less than " << this->m_nGridColumns << "."
                      << std::endl;
            iColumn = -1;
        }
    }

    std::tuple<int, int> tupleCoord = std::make_tuple(iRow, iColumn);
    return tupleCoord;
}

void Game::play()
{
    int iRow = 0;
    int iColumn = 0;

    this->reset();
    this->displayGrid(false);
    std::cout << "Magazine: " << this->m_nTorpedoes << " torpedoes" << std::endl;
    std::cout << std::endl;

    // Execute a sequence of turns within a while loop. Each turn is an interaction
    // of the file loop. Within a turn, the user fires a torpedo and checks are
    // performed to see if the torpedo hit the target (i.e. the user selected the
    // exact grid square in which the target boat is placed), if the torpedo was
    // "close" to the target (i.e. aimed at a grid square adjacent to the target
    // boat. If neither a hit (isOnTarget is true) or a close miss (isCloseToTarget is true)
    // the torpedo is a miss. The while loop iterates until either the target boat
    // is hit (and thus sunk), in which case the player wins, or all torpedoes have
    // been expended, and the target boat survives, in which case the computer wins.
    bool bSunk = false;
    while ((!bSunk) && (this->m_nTorpedoes > 0))
    {
        std::cout << std::endl;
        // Accept input from user as to grid location where torpedo is fired
        // Return location as a tuple and extract the row and column values
        // from the tuple into iRow and iColumn, respectively.
        std::tie(iRow, iColumn) = this->fireTorpedo();

        if (this->isOnTarget(iRow, iColumn))
        {
            this->showSunk();
            this->displayGrid(false);
            std::cout << "Hit!  Kaboom!" << std::endl;
            std::cout << "Victory!" << std::endl;
            bSunk = true;
        }
        else if (this->isCloseToTarget(iRow, iColumn))
        {
            this->displayGrid(false);
            std::cout << "Location row: " << iRow << "; column: " << iColumn << " is close!" << std::endl;
        }
        else
        {
            this->displayGrid(false);
            std::cout << "Location row: " << iRow << "; column: " << iColumn << " is a miss." << std::endl;
        }

        if (!bSunk)
        {
            std::cout << "Magazine: " << this->m_nTorpedoes << " torpedoes" << std::endl;
        }

        if (this->m_nTorpedoes == 0 && !bSunk)
        {
            this->displayGrid(true);
            std::cout << "Torpedoes expended" << std::endl;
            std::cout << "Game over" << std::endl;
        }
    }
}


void Game::reset()
{
    this->initializeGrid();
#if defined TEST
    // Place the target boat at a specified location for testing/diagnostic purposes.
	// This code is executed only if the TEST macro is defined (#define TEST or -DTEST).
	// If the macro is defined, the program is in "test mode."
	this->placeBoat();
#else
    // The target boat is placed at a random location on the grid; this is used for
    // normal gameplay.
    this->placeBoatRandomly();
#endif
    this->m_nTorpedoes = Game::k_nMaxTorpedoes;
}
