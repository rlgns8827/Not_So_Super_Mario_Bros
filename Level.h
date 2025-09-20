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
    int size;       
    char** grid;    

public:
    Level(int n);   // Constructor
    ~Level();       // Destructor


    void populateLevel(int coinPct, int emptyPct, int goombaPct, int koopaPct, int mushroomPct, bool hasWarp);
    void placeObject(char object); // Place one object at random location

    void printLevel(std::ofstream& logFile); // Output level state
    char getPosition(int row, int col); // Get object at position
    void setPosition(int row, int col, char object); // Set object at position
    
    int getSize();  // Return grid size
    bool bossExists() const;  // Check if boss is still in grid
};

#endif



