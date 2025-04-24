// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 2: Not So Super Mario Bros

#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include "Mario.h"
#include <fstream>
#include <string>

class World {
public:
    int levels;           // Number of levels in the game
    Level** gameLevels;   // Array of pointers to Level instances
    Mario* mario;         // Pointer to the player character

    // Constructor: Builds the world using config from input file
    World(std::string inputFile);

    // Destructor: Clean up level and Mario memory
    ~World();

    // Simulate gameplay for a given level
    void playLevel(int levelIdx, std::ofstream& logFile);

    // Move Mario around the level and log his interactions
    void moveMario(Level* level, int levelIdx, std::ofstream& logFile);
};

#endif  // WORLD_H

