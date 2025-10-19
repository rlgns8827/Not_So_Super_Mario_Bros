# Not_So_Super_Mario_Bros

## Project Description
This project is a C++ simulation inspired by the classic Super Mario Bros. game, designed for Data Structures and Algorithms. The objective is to guide Mario through a world of multiple levels filled with coins, mushrooms, enemies (Goombas and Koopas), warp pipes, and level bosses.
Mario moves randomly across each level's NxN toroidal grid, interacting with elements based on defined rules. He gains coins, levels up with mushrooms, and battles enemies with probabilistic outcomes. The game ends when Mario either defeats the final boss or runs out of lives.

Originally developed for Chapman University's CPSC 350: Data Structures course, this project demonstrates object-oriented design, game logic, and file I/O in C++.

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

