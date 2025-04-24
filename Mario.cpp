// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 2: Not So Super Mario Bros

// This file defines the Mario class, representing the player character with logic for
// collecting items, fighting enemies, and managing lives and power levels.

#include "Mario.h"
#include <cstdlib>

// Constructor: Initializes Mario's lives, coins, power level, and enemy defeat counter
Mario::Mario(int initialLives) {
    lives = initialLives;
    coins = 0;
    powerLevel = PL0;
    enemiesDefeated = 0;
}

// Called when Mario collects a coin
// Increases coin count and grants an extra life for every 20 coins
void Mario::collectCoin() {
    coins++;
    if (coins == 20) {
        lives++;     // Gain extra life
        coins = 0;   // Reset coin count
    }
}

// Called when Mario eats a mushroom
// Increases power level by 1, up to PL2
void Mario::eatMushroom() {
    if (powerLevel < PL2) {
        powerLevel = static_cast<PowerLevel>(powerLevel + 1);
    }
}

// Called when Mario fights a regular enemy (Goomba or Koopa)
// Returns true if Mario wins, false if he loses
bool Mario::fightEnemy(char enemyType) {
    int winChance = (enemyType == 'g') ? 80 : 65;  // Goomba: 80%, Koopa: 65%
    int roll = rand() % 100;

    if (roll < winChance) {
        enemiesDefeated++;
        // Gain extra life after 7 consecutive wins
        if (enemiesDefeated == 7) {
            lives++;
            enemiesDefeated = 0;
        }
        return true;  // Victory
    } else {
        enemiesDefeated = 0;  // Reset win streak
        // Lose life or power depending on current power level
        if (powerLevel == PL0) {
            lives--;
        } else {
            powerLevel = static_cast<PowerLevel>(powerLevel - 1);
        }
        return false;  // Defeat
    }
}

// Called when Mario fights a level boss
// 50% win chance; if lost, power drops to PL0 and possibly lose a life
bool Mario::fightBoss() {
    int roll = rand() % 100;

    if (roll < 50) {
        enemiesDefeated = 0;
        return true;  // Victory
    } else {
        enemiesDefeated = 0;
        // If power is low, lose a life and reset to PL0
        if (powerLevel == PL0 || powerLevel == PL1) {
            lives--;
            powerLevel = PL0;
        } else {
            powerLevel = PL0;
        }
        return false;  // Defeat
    }
}


