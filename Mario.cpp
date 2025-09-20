// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 2: Not So Super Mario Bros


#include "Mario.h"
#include <cstdlib>

// Constructor: Initializes Mario's lives, coins, power level, and enemy defeat counter
Mario::Mario(int initialLives) {
    lives = initialLives;
    coins = 0;
    powerLevel = PL0;
    enemiesDefeated = 0;
}

// Handle coin collection and extra life at 20 coins
void Mario::collectCoin() {
    coins++;
    if (coins == 20) {
        lives++;     
        coins = 0;   
    }
}

// Increase power level if below PL2
void Mario::eatMushroom() {
    if (powerLevel < PL2) {
        powerLevel = static_cast<PowerLevel>(powerLevel + 1);
    }
}

// Fight Goomba or Koopa based on win chance
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
        if (powerLevel == PL0) {
            lives--;
        } else {
            powerLevel = static_cast<PowerLevel>(powerLevel - 1);
        }
        return false;  // Defeat
    }
}

// Fight boss with 50% chance; lose power/life if defeated
bool Mario::fightBoss() {
    // https://www.w3schools.com/cpp/cpp_howto_random_number.asp
    int roll = rand() % 100;
    // https://www.w3schools.com/cpp/cpp_howto_random_number.asp

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




