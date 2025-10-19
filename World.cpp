// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 2: Not So Super Mario Bros

#include "World.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Constructor 
World::World(std::string inputFile) {
    std::ifstream file(inputFile);
    if (!file) {
        std::cerr << "Error: Unable to open input file!\n";
        exit(1); // terminate if input file cannot be opened
    }

    // Read configuration parameters from the input file
    int gridSize, lives, coinPct, emptyPct, goombaPct, koopaPct, mushroomPct;
    file >> levels >> gridSize >> lives;
    file >> coinPct >> emptyPct >> goombaPct >> koopaPct >> mushroomPct;
    file.close();

    mario = new Mario(lives);           // dynamically allocate Mario object
    gameLevels = new Level*[levels];    // create dynamic array of Level pointers

    // Populate each level using given percentages
    for (int i = 0; i < levels; i++) {
        gameLevels[i] = new Level(gridSize);
        gameLevels[i]->populateLevel(coinPct, emptyPct, goombaPct, koopaPct, mushroomPct, (i != levels - 1));
    }
}

// Destructor 
World::~World() {
    delete mario;
    for (int i = 0; i < levels; i++) {
        delete gameLevels[i];
    }
    delete[] gameLevels;
}

// Main Level Loop 
void World::playLevel(int levelIdx, std::ofstream& logFile) {
    logFile << "==========\n";

    Level* currentLevel = gameLevels[levelIdx];
    int gridSize = currentLevel->getSize();

    // Random starting position for Mario in this level
    mario->row = rand() % gridSize;
    mario->col = rand() % gridSize;

    logFile << "Mario is starting in position: (" << mario->row << "," << mario->col << ")\n";
    logFile << "==========\n";

    // Place Mario and print the initial layout
    currentLevel->setPosition(mario->row, mario->col, 'H');
    currentLevel->printLevel(logFile);

    int moveCount = 0;
    const int MAX_MOVES = 500; // limit per level to prevent infinite loops

    // Continue while Mario is alive and hasn't exceeded move limit
    while (mario->lives > 0 && moveCount < MAX_MOVES) {
        char tile = currentLevel->getPosition(mario->row, mario->col);

        // Boss encounter check
        if (tile == 'b') {
            bool won = mario->fightBoss();
            logFile << "Level: " << levelIdx << ". Mario is at position: (" << mario->row << "," << mario->col
                    << "). Mario fought the level boss and " << (won ? "won." : "lost.")
                    << " Mario has " << mario->lives << " lives left. Mario is at power level "
                    << mario->powerLevel << ".\n";
            currentLevel->printLevel(logFile);

            if (won) {
                currentLevel->setPosition(mario->row, mario->col, 'x'); // clear boss tile
                if (levelIdx == levels - 1) {
                    logFile << "Mario Wins! The princess is saved!\n";
                }
                return; // exit this level
            } else {
                continue; // retry boss fight if Mario lost
            }
        }

        moveMario(currentLevel, levelIdx, logFile); // perform a move
        moveCount++;

        // Check if Mario reached a warp pipe
        char postMove = currentLevel->getPosition(mario->row, mario->col);
        if (postMove == 'w') {
            currentLevel->setPosition(mario->row, mario->col, 'x');
            logFile << "Level: " << levelIdx << ". Mario is at position: (" << mario->row << "," << mario->col
                    << "). Mario warped to the next level!\n";
            return;
        }
    }

    // enforce 500-move cutoff cleanly to prevent infinite simulation
    if (moveCount >= MAX_MOVES) {
        logFile << "Level: " << levelIdx << ". Mario exceeded " << MAX_MOVES
                << " moves and is considered stuck.\n";
        return;
    }

    // loss condition (Mario dies)
    if (mario->lives <= 0) {
        logFile << "WE LOST THE GAME! :(\n";
        // "Mario Lost!" printed in main.cpp to avoid duplicates
    }
}

// Movement and Interaction
void World::moveMario(Level* level, int levelIdx, std::ofstream& logFile) {
    int direction = rand() % 4; // pick random direction (0–3)
    int size = level->getSize();
    int newRow = mario->row;
    int newCol = mario->col;

    std::string dirStr;
    if (direction == 0) { newRow = (mario->row - 1 + size) % size; dirStr = "UP"; }
    else if (direction == 1) { newRow = (mario->row + 1) % size; dirStr = "DOWN"; }
    else if (direction == 2) { newCol = (mario->col - 1 + size) % size; dirStr = "LEFT"; }
    else { newCol = (mario->col + 1) % size; dirStr = "RIGHT"; }

    // Announce Mario’s move BEFORE actually changing position
    logFile << "Level: " << levelIdx << ". Mario is at position: (" << mario->row << "," << mario->col
            << "). Mario is at power level " << mario->powerLevel
            << ". Mario will move " << dirStr << ".\n";

    // Update Mario’s position (wrap-around movement)
    level->setPosition(mario->row, mario->col, 'x');
    mario->row = newRow;
    mario->col = newCol;

    char obj = level->getPosition(mario->row, mario->col);
    std::string action;

    // Handle object interactions
    switch (obj) {
        case 'x': action = "Mario visited an empty space."; break;
        case 'c': mario->collectCoin(); action = "Mario collected a coin."; break;
        case 'm': mario->eatMushroom(); action = "Mario ate a mushroom."; break;
        case 'g': {
            bool won = mario->fightEnemy('g');
            action = won ? "Mario encountered a Goomba and won." : "Mario encountered a Goomba and lost.";
            if (won) level->setPosition(mario->row, mario->col, 'x'); // clear defeated Goomba
            break;
        }
        case 'k': {
            bool won = mario->fightEnemy('k');
            action = won ? "Mario encountered a Koopa and won." : "Mario encountered a Koopa and lost.";
            if (won) level->setPosition(mario->row, mario->col, 'x'); // clear defeated Koopa
            break;
        }
        case 'w': action = "Mario found a warp pipe."; break;
        default: action = "Mario encountered an unknown tile."; break;
    }

    // Mark Mario’s new location and log outcome
    level->setPosition(mario->row, mario->col, 'H');
    logFile << action << " Mario has " << mario->lives << " lives left. Mario has "
            << mario->coins << " coins.\n";

    // Print current level grid after each move
    level->printLevel(logFile);
}


