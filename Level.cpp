// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 2: Not So Super Mario Bros

// This file defines the Level class, which models an NxN grid-based level in the Mario simulation.

#include "Level.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

// Constructor: Initializes a size x size grid with all positions set to 'x' (empty)
Level::Level(int n) {
    size = n;
    grid = new char*[size];
    for (int i = 0; i < size; i++) {
        grid[i] = new char[size];
        std::memset(grid[i], 'x', size * sizeof(char));  // Fill each row with 'x'
    }
}

// Destructor: Deallocates dynamically allocated memory for the grid
Level::~Level() {
    for (int i = 0; i < size; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

// Fills the level with objects based on percentage values
// Also places exactly one boss, and a warp pipe if hasWarp is true
void Level::populateLevel(int coinPct, int emptyPct, int goombaPct, int koopaPct, int mushroomPct, bool hasWarp) {
    int totalCells = size * size;

    int numCoins = (totalCells * coinPct) / 100;
    int numGoombas = (totalCells * goombaPct) / 100;
    int numKoopas = (totalCells * koopaPct) / 100;
    int numMushrooms = (totalCells * mushroomPct) / 100;

    // Randomly place each object
    for (int i = 0; i < numCoins; i++) placeObject('c');
    for (int i = 0; i < numGoombas; i++) placeObject('g');
    for (int i = 0; i < numKoopas; i++) placeObject('k');
    for (int i = 0; i < numMushrooms; i++) placeObject('m');

    // Place boss and optional warp pipe
    placeObject('b');
    if (hasWarp) placeObject('w');
}

// Randomly places an object at an empty grid position
void Level::placeObject(char object) {
    int r, c;
    do {
        r = rand() % size;
        c = rand() % size;
    } while (grid[r][c] != 'x');  // Keep finding until an empty space is found

    grid[r][c] = object;
}

// Prints the current grid state to the output log file
void Level::printLevel(std::ofstream& logFile) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            logFile << grid[i][j] << ' ';
        }
        logFile << '\n';
    }
    logFile << "==========\n";
}

// Gets the object at a given grid position
char Level::getPosition(int row, int col) {
    return grid[row][col];
}

// Sets the object at a specific grid position
void Level::setPosition(int row, int col, char object) {
    grid[row][col] = object;
}

// Returns the size of the level (N)
int Level::getSize() {
    return size;
}

// Checks if a boss ('b') still exists in the level
bool Level::bossExists() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == 'b') return true;
        }
    }
    return false;
}
