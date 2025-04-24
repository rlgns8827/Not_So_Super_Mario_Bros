// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 2: Not So Super Mario Bros

#ifndef LEVEL_H
#define LEVEL_H

#include <fstream>

class Level {
private:
    int size;       // NxN grid size
    char** grid;    // 2D grid for storing level items

public:
    Level(int n);   // Constructor
    ~Level();       // Destructor

    // Populate grid with elements by percentage and add boss/warp
    void populateLevel(int coinPct, int emptyPct, int goombaPct, int koopaPct, int mushroomPct, bool hasWarp);

    // Place specific object at a random empty location
    void placeObject(char object);

    // Output current level to logfile
    void printLevel(std::ofstream& logFile);

    // Access and modify individual positions
    char getPosition(int row, int col);
    void setPosition(int row, int col, char object);

    // Return grid size
    int getSize();

    // Check if boss is still alive in the level
    bool bossExists() const;
};

#endif

