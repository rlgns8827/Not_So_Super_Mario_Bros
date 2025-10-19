// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 2: Not So Super Mario Bros

#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include "Mario.h"
#include <fstream>
#include <string>

class World {
public:
    int levels;           // Number of levels
    Level** gameLevels;   // Array of levels
    Mario* mario;         // Player character

    World(std::string inputFile); // Constructor builds world
    ~World();                     // Destructor cleans memory

    void playLevel(int levelIdx, std::ofstream& logFile);  // Simulate one level
    void moveMario(Level* level, int levelIdx, std::ofstream& logFile); // Mario moves & acts
};

#endif

