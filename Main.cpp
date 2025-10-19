// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 2: Not So Super Mario Bros

#include "World.h"
#include <iostream>
#include <fstream>
#include <ctime>

int main(int argc, char* argv[]) {
    // Validate command-line arguments
    if (argc != 3) {
        std::cerr << "Usage: ./game input.txt output.txt\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);    
    std::ofstream logFile(argv[2]);      

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file.\n";
        return 1;
    }

    if (!logFile.is_open()) {
        std::cerr << "Failed to open output file.\n";
        return 1;
    }

    srand(static_cast<unsigned>(time(0))); // Seed RNG

    World world(argv[1]);  // Build world from input file

    // Print all levels before Mario starts
    for (int i = 0; i < world.levels; ++i) {
        logFile << "==========\nInitial layout for Level " << i << ":\n";
        world.gameLevels[i]->printLevel(logFile);
    }

    // Play each level while Mario has lives
    for (int i = 0; i < world.levels && world.mario->lives > 0; ++i) {
        world.playLevel(i, logFile);
        if (world.mario->lives <= 0) break;
    }

    // Print game result to log file
    if (world.mario->lives > 0) {
        logFile << "Mario Wins!\n";
    } else {
        logFile << "Mario Lost!\n";
    }

    logFile.close();
    return 0;
}




