# Not_So_Super_Mario_Bros

## Identifying Information: 
1. Full name: Kihoon Yoo
2. Student ID: 2480883
3. Chapman Email: kiyoo@chapman.edu
4. Course number and section: CPSC-350-04
5. Assignment or exercise number: PA2: Not So Super Mario Bros

## Project Description
This project is a C++ simulation inspired by the classic Super Mario Bros. game, designed for Data Structures and Algorithms. The objective is to guide Mario through a world of multiple levels filled with coins, mushrooms, enemies (Goombas and Koopas), warp pipes, and level bosses.
Mario moves randomly across each level's NxN toroidal grid, interacting with elements based on defined rules. He gains coins, levels up with mushrooms, and battles enemies with probabilistic outcomes. The game ends when Mario either defeats the final boss or runs out of lives.

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
10. program
11. README.md

## Known Error 
- There are no known errors in this program.

## References
- https://www.w3schools.com/cpp/cpp_howto_random_number.asp
- https://www.geeksforgeeks.org/switch-statement-in-cpp/
- https://www.tutorialspoint.com/cplusplus-program-to-read-file-word-by-word#:~:text=The%20task%20is%20very%20simple,each%20word%20one%20by%20one
- https://www.geeksforgeeks.org/switch-statement-in-cpp/
- Received debugging help from the Chapman TLC
- Received additional debugging help from Dr.Stevens

## Instructions for compiling
- To compile: g++ Main.cpp Level.cpp Mario.cpp World.cpp -o program
- To run: ./program input.txt output.txt

