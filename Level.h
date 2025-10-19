// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 2: Not So Super Mario Bros

#ifndef LEVEL_H
#define LEVEL_H

#include <fstream>

class Level {
private:
    int size;      // dimensions of the level grid (size x size)
    char** grid;   // 2D dynamic array representing the level

public:
    // Constructor & Destructor
    Level(int size);
    ~Level();

    // Populate level with random objects using percentage values
    void populateLevel(int coinPct, int emptyPct, int goombaPct,
                       int koopaPct, int mushroomPct, bool includeWarp);

    void printLevel(std::ofstream& logFile); // Print the current grid layout to the output file
    char getPosition(int row, int col); // Get the character at a given grid position
    void setPosition(int row, int col, char symbol); // Set the character at a given grid position
    int getSize(); // Return the size of the level grid
};

#endif



