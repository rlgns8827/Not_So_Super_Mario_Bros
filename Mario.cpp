// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 2: Not So Super Mario Bros

#include "Mario.h"
#include <cstdlib>

// Constructor 
Mario::Mario(int initialLives) {
    lives = initialLives;
    coins = 0;
    enemiesDefeated = 0;
    powerLevel = PL0;
    row = 0;
    col = 0;
}

// Collect Coin
void Mario::collectCoin() {
    coins++;

    // Every 20 coins gives Mario one extra life
    if (coins % 20 == 0) {
        lives++;
    }
}

// Eat Mushroom 
void Mario::eatMushroom() {
    // Power levels: PL0 -> PL1 -> PL2
    if (powerLevel == PL0)
        powerLevel = PL1;
    else if (powerLevel == PL1)
        powerLevel = PL2;
    // If already PL2, no further change
}

// Fight Regular Enemy 
bool Mario::fightEnemy(char enemyType) {
    int winChance;

    // Assign base win probabilities depending on enemy type
    if (enemyType == 'g') {         // Goomba
        winChance = 80;
    } else if (enemyType == 'k') {  // Koopa
        winChance = 65;
    } else {                        // Unknown type — assume easy win
        winChance = 100;
    }

    int roll = rand() % 100; // random value 0–99

    if (roll < winChance) {
        enemiesDefeated++;

        // Every 7 enemies defeated gives Mario one extra life
        if (enemiesDefeated % 7 == 0) {
            lives++;
        }
        return true; // Mario wins the encounter
    } else {
        // Losing a fight costs a life or power level depending on state
        if (powerLevel == PL2)
            powerLevel = PL1;
        else if (powerLevel == PL1)
            powerLevel = PL0;
        else
            lives--;

        return false; // Mario lost the encounter
    }
}

// Fight Level Boss 
bool Mario::fightBoss() {
    int winChance = 50;  // base chance to defeat boss
    int roll = rand() % 100;

    if (roll < winChance) {
        // Successful boss fight rewards an extra life
        lives++;
        return true;
    } else {
        // Losing to boss reduces power level or life
        if (powerLevel == PL2)
            powerLevel = PL1;
        else if (powerLevel == PL1)
            powerLevel = PL0;
        else
            lives--;

        return false;
    }
}




