// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 2: Not So Super Mario Bros

// This file contains the entry point for the simulation.
// It reads input and output file names from command-line arguments,
// constructs the game world, and runs through all levels until Mario wins or loses.

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

    std::ifstream inputFile(argv[1]);    // Input file: level config
    std::ofstream logFile(argv[2]);      // Output file: move log

    // Check if input file opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file.\n";
        return 1;
    }

    // Check if output file opened successfully
    if (!logFile.is_open()) {
        std::cerr << "Failed to open output file.\n";
        return 1;
    }

    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    World world(argv[1]);  // Construct world using input configuration

    // Loop through each level while Mario still has lives
    for (int i = 0; i < world.levels && world.mario->lives > 0; ++i) {
        world.playLevel(i, logFile);     // Play current level
        if (world.mario->lives <= 0) break; // If Mario dies, stop game
    }

    // Print game result to log file
    if (world.mario->lives > 0) {
        logFile << "Mario Wins!\n";
    } else {
        logFile << "Mario Lost!\n";
    }

    logFile.close(); // Finalize output
    return 0;
}
