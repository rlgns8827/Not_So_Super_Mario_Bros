// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 2: Not So Super Mario Bros

#include "Level.h"
#include <cstdlib>
#include <iostream>

// Constructor 
Level::Level(int size) {
    this->size = size;
    grid = new char*[size];

    // Allocate a square grid dynamically
    for (int i = 0; i < size; ++i) {
        grid[i] = new char[size];
    }
}

// Destructor
Level::~Level() {
    for (int i = 0; i < size; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

// Populate the Level 
void Level::populateLevel(int coinPct, int emptyPct, int goombaPct, int koopaPct, int mushroomPct, bool includeWarp) {
    // Randomly fill the grid using given object percentages.
    // The remaining percentage (after summing given values) automatically becomes empty spaces.

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int roll = rand() % 100; // random number between 0–99

            if (roll < coinPct)
                grid[i][j] = 'c'; // coin
            else if (roll < coinPct + emptyPct)
                grid[i][j] = 'x'; // empty
            else if (roll < coinPct + emptyPct + goombaPct)
                grid[i][j] = 'g'; // Goomba
            else if (roll < coinPct + emptyPct + goombaPct + koopaPct)
                grid[i][j] = 'k'; // Koopa
            else if (roll < coinPct + emptyPct + goombaPct + koopaPct + mushroomPct)
                grid[i][j] = 'm'; // Mushroom
            else
                grid[i][j] = 'x'; // Default filler
        }
    }

    // Place the boss 'b' at a random location
    int bossRow = rand() % size;
    int bossCol = rand() % size;
    grid[bossRow][bossCol] = 'b';

    // Optionally include a warp pipe to the next level
    if (includeWarp) {
        int warpRow = rand() % size;
        int warpCol = rand() % size;
        grid[warpRow][warpCol] = 'w';
    }
}

// Print Current Grid 
void Level::printLevel(std::ofstream& logFile) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            logFile << grid[i][j] << " ";
        }
        logFile << "\n";
    }
    logFile << "==========\n";
}

// Get Object at Position
char Level::getPosition(int row, int col) {
    return grid[row][col];
}

// Set Object at Position 
void Level::setPosition(int row, int col, char symbol) {
    grid[row][col] = symbol;
}

// Get Grid Size 
int Level::getSize() {
    return size;
}

