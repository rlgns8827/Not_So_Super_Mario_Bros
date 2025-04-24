// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 2: Not So Super Mario Bros

#include "World.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Constructor: Initializes the world based on input file parameters
World::World(std::string inputFile) {
    std::ifstream file(inputFile);
    if (!file) {
        std::cerr << "Error: Unable to open input file!" << std::endl;
        exit(1);
    }

    int gridSize, lives, coinPct, emptyPct, goombaPct, koopaPct, mushroomPct;
    file >> levels >> gridSize >> lives;
    file >> coinPct >> emptyPct >> goombaPct >> koopaPct >> mushroomPct;
    file.close();

    mario = new Mario(lives);
    gameLevels = new Level*[levels];

    // Create and populate each level
    for (int i = 0; i < levels; i++) {
        gameLevels[i] = new Level(gridSize);
        gameLevels[i]->populateLevel(coinPct, emptyPct, goombaPct, koopaPct, mushroomPct, (i != levels - 1));
    }
}

// Destructor: Frees dynamically allocated memory
World::~World() {
    delete mario;
    for (int i = 0; i < levels; i++) {
        delete gameLevels[i];
    }
    delete[] gameLevels;
}

// Simulates Mario playing a single level
void World::playLevel(int levelIdx, std::ofstream& logFile) {
    logFile << "==========\n";

    Level* currentLevel = gameLevels[levelIdx];
    int gridSize = currentLevel->getSize();

    // Start Mario at a random position
    mario->row = rand() % gridSize;
    mario->col = rand() % gridSize;

    logFile << "Mario is starting in position: (" << mario->row << "," << mario->col << ")\n";
    logFile << "==========\n";
    currentLevel->setPosition(mario->row, mario->col, 'H');
    currentLevel->printLevel(logFile);

    int moveCount = 0;
    const int MAX_MOVES = 500; // Prevent infinite looping

    while (mario->lives > 0 && moveCount < MAX_MOVES) {
        char current = currentLevel->getPosition(mario->row, mario->col);

        // If Mario encounters a boss
        if (current == 'b') {
            bool won = mario->fightBoss();
            logFile << "Level: " << levelIdx << ". Mario is at position: (" << mario->row << "," << mario->col << "). Mario fought the level boss and " << (won ? "won." : "lost.")
                    << " Mario has " << mario->lives << " lives left. Mario is at power level " << mario->powerLevel << ".\n";

            if (won) {
                currentLevel->setPosition(mario->row, mario->col, 'x');
                currentLevel->printLevel(logFile);

                if (levelIdx == levels - 1) {
                    logFile << "Mario Wins! The princess is saved!\n";
                    return;
                }
                return; // Proceed to next level
            } else {
                currentLevel->printLevel(logFile);
                continue; // Retry boss
            }
        }

        // Move Mario and interact with environment
        moveMario(currentLevel, levelIdx, logFile);
        moveCount++;

        // Check if Mario stepped on a warp pipe
        char postMove = currentLevel->getPosition(mario->row, mario->col);
        if (postMove == 'w') {
            currentLevel->setPosition(mario->row, mario->col, 'x');
            logFile << "Level: " << levelIdx << ". Mario is at position: (" << mario->row << "," << mario->col << "). Mario warped to the next level!\n";
            return;
        }
    }

    // Max moves reached
    if (moveCount >= MAX_MOVES) {
        logFile << "Level: " << levelIdx << ". Mario exceeded the maximum number of moves (" << MAX_MOVES << ") and is considered stuck. Moving to next level or ending game.\n";
    }

    // Out of lives
    if (mario->lives <= 0) {
        logFile << "WE LOST THE GAME! :(\n";
    }
}

// Handles Mario's movement and logs interactions
void World::moveMario(Level* level, int levelIdx, std::ofstream& logFile) {
    int direction = rand() % 4;
    int size = level->getSize();
    int newRow = mario->row;
    int newCol = mario->col;

    std::string dirStr;
    if (direction == 0) { newRow = (mario->row - 1 + size) % size; dirStr = "UP"; }
    else if (direction == 1) { newRow = (mario->row + 1) % size; dirStr = "DOWN"; }
    else if (direction == 2) { newCol = (mario->col - 1 + size) % size; dirStr = "LEFT"; }
    else { newCol = (mario->col + 1) % size; dirStr = "RIGHT"; }

    char obj = level->getPosition(newRow, newCol);
    std::string action;

    // Clear Mario's old position
    level->setPosition(mario->row, mario->col, 'x');
    mario->row = newRow;
    mario->col = newCol;

    // React to object on new tile
    switch (obj) {
        case 'x': action = "Mario visited an empty space."; break;
        case 'c': mario->collectCoin(); action = "Mario collected a coin."; break;
        case 'm': mario->eatMushroom(); action = "Mario ate a mushroom."; break;
        case 'g': {
            bool won = mario->fightEnemy('g');
            action = won ? "Mario encountered a Goomba and won." : "Mario encountered a Goomba and lost.";
            if (won) level->setPosition(mario->row, mario->col, 'x');
            break;
        }
        case 'k': {
            bool won = mario->fightEnemy('k');
            action = won ? "Mario encountered a Koopa and won." : "Mario encountered a Koopa and lost.";
            if (won) level->setPosition(mario->row, mario->col, 'x');
            break;
        }
        case 'w': action = "Mario found a warp pipe."; break;
        default: action = "Mario encountered an unknown tile."; break;
    }

    // Mark Mario's new position
    level->setPosition(mario->row, mario->col, 'H');

    // Log status
    logFile << "Level: " << levelIdx << ". Mario is at position: (" << mario->row << "," << mario->col
            << "). Mario is at power level " << mario->powerLevel << ". " << action << " Mario has " << mario->lives
            << " lives left. Mario has " << mario->coins << " coins. Mario will move " << dirStr << ".\n";

    level->printLevel(logFile);
}

