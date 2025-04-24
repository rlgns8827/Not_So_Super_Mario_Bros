Kihoon Yoo
2486883
kiyoo@chapman.edu 
CPSC-350-04
PA 2 : Not So Super Mario Bros

List of source files:
-Level.cpp
-Level.h
-Mario.h
-Mario.cpp
-World.h         
-World.cpp
-Main.cpp

Notable Compiling Errors:
- Main.cpp:(.text+0x101): undefined reference to World::playLevel(int, std::basic_ofstream<char, std::char_traits<char> >&)'
collect2: error: ld returned 1 exit status
- usage ./game input.txt output.txt
- Main.cpp: In function ‘int main(int, char**)’:
- Main.cpp:26:49: error: invalid operands of types ‘int’ and ‘void’ to binary ‘operator+’
         totalMoves += world.playLevel(i, logFile);
                                                 ^
- Main.cpp:26:49: error:   in evaluation of ‘operator+=(int, void)’
    World.cpp:43:5: error: prototype for ‘int World::playLevel(int, std::ofstream&)’ does not match any in class ‘World’
    int World::playLevel(int levelIdx, std::ofstream& logFile) {
     ^~~~~
-In file included from World.cpp:7:0:
    World.h:22:10: error: candidate is: void World::playLevel(int, std::ofstream&)
     void playLevel(int levelIdx, std::ofstream& logFile);
          ^~~~~~~~~
- Level.cpp: At global scope:
    Level.cpp:44:36: error: no ‘void Level::placeObject(char)’ member function declared in class ‘Level’
    void Level::placeObject(char object) {          

Reference from following:
    https://www.w3schools.com/cpp/cpp_howto_random_number.asp
    https://www.geeksforgeeks.org/switch-statement-in-cpp/
    https://www.tutorialspoint.com/cplusplus-program-to-read-file-word-by-word#:~:text=The%20task%20is%20very%20simple,each%20word%20one%20by%20one
    https://www.geeksforgeeks.org/switch-statement-in-cpp/
    https://chatgpt.com/

Instructions for compiling:
    To compile: g++ Main.cpp Level.cpp Mario.cpp World.cpp -o program
    To run: ./program input.txt output.txt

