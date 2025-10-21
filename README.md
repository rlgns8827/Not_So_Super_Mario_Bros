# Not_So_Super_Mario_Bros

## Project Description
This project showcases my proficiency in data structures and algorithms with a focus on array manipulation and object-oriented programming in C++. The simulation of Super Mario involves reading level data from input files, processing and managing gameplay states, and writing results to output files. Mario navigates through a multi-level world represented by a 3D array, interacting dynamically with his environment through a series of conditional events and game logic structures.


## Key Features
- Mario Simulation: Simulates Mario navigating the grid, interacting with the environment, battling enemies, collecting coins, eating mushrooms, and moving through levels.
- Randomized World Generation: Builds a multi-level world based on runtime parameters, with randomized placement of coins, enemies, mushrooms, bosses, and warp pipes.
- Life and Power Management: Tracks Mario’s lives, coins (extra lives earned after collecting 20 coins), and power levels (PL0, PL1, PL2).
- Battle Logic: Includes probabilistic outcomes for battles against Goombas, Koopas, and Bosses, affecting Mario’s survival and power level.
- Toroidal Grid Movement: Implements grid wrapping horizontally and vertically to allow continuous movement (torus behavior).
- Warp Pipes: Allows Mario to instantly advance to the next level if a warp pipe is found.
- Detailed Logging: Records every move Mario makes into an output text file, including actions taken, Mario’s state, and the updated map.
- Array-Only Data Structure: Implements the world using a 3D L x N x N array of characters without using any advanced data structures like vector or list.

## Files
1. Level.cpp
2. Level.h
3. Main.cpp
4. Mario.h
5. Mario.cpp
6. World.h
7. World.cpp
8. input.txt
9. output.txt
10. README.md


## Instructions for compiling
- To compile: g++ *.cpp -o mario
- To run: /mario input.txt output.txt

