// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 2: Not So Super Mario Bros

#ifndef MARIO_H
#define MARIO_H

// Enumeration representing Mario's power levels
enum PowerLevel { PL0, PL1, PL2 };

class Mario {
public:
    int lives;             // number of lives remaining
    int coins;             // number of coins collected
    PowerLevel powerLevel; // current power state (PL0–PL2)
    int row, col;          // current position in grid
    int enemiesDefeated;   // count of enemies defeated

    // Constructor
    Mario(int initialLives);
    void collectCoin(); // Collect a coin; every 20 coins grant an extra life
    void eatMushroom(); // Eat a mushroom; increases Mario's power level (up to PL2)
    bool fightEnemy(char enemyType); // Handle fight with a regular enemy (Goomba or Koopa)    
    bool fightBoss(); // Handle fight with the boss of a level
};

#endif

