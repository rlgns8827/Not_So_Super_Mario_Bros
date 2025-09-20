// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 2: Not So Super Mario Bros

#ifndef MARIO_H
#define MARIO_H

// Enumeration for Mario's power levels
enum PowerLevel { PL0, PL1, PL2 };

class Mario {
public:
    int lives;             // Number of lives Mario has
    int coins;             // Number of coins Mario has collected
    PowerLevel powerLevel; // Current power level (PL0, PL1, PL2)
    int row, col;          // Mario's current position in the grid
    int enemiesDefeated;   // Count of enemies defeated on current life

    // Constructor
    Mario(int initialLives);

    // Game mechanics
    void collectCoin();             // Collect a coin and possibly gain a life
    void eatMushroom();             // Increase power level if not at max
    bool fightEnemy(char enemyType); // Fight Goomba ('g') or Koopa ('k')
    bool fightBoss();               // Fight a boss (50/50 win chance)
};

#endif

