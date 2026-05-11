/* Filename: combat.h
 * Description: Header which contains functions for dice roll style combat.
 * Author: Liam Kinslow
 * Date: 02/04/2023
 * Input/Output: None
 * Version: 2.0
*/
#ifndef FLATLANDIA_GAME_COMBAT_H
#define FLATLANDIA_GAME_COMBAT_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "object.h"

// Function which tells the player if they have encountered an enemy and moves to the combat function
void enemy_collision() {
    for (int i = 5; i < 10; i++) {
        if (objs[i].location == objs[10].location) {
            struct objects *enemy = &objs[i];
            printf("\nYou have encountered %s\n", objs[i].description);
            getchar();
            printf("It prepares to attack you.");
            getchar();
            combat(enemy);
            break;
        }
    }
}

// Function for d20 roll combat.
void combat(struct objects *enemy) {
    struct objects *player = &objs[10];
    printf("\nYou have %d health.\n", player->health);
    printf("The %s has %d health.\n", enemy->tag, enemy->health);

// While loop that ends when the enemy reaches zero health.

    while (enemy->health > 0) {
        int player_roll = roll_d20();
        int enemy_roll = roll_d20();
        getchar();
        printf("\nEnter 'a' to attack, or 'i' to use an item: ");
        char choice;
        scanf("%s", &choice);

        // Player chooses to attack statement.
        if (choice == 'a') {
            printf("You roll a %d!\n", player_roll);
            printf("The %s rolls a %d!\n", enemy->tag, enemy_roll);
            // Statement and events if the player damages the enemy.
            if (player_roll > enemy_roll) {
                int damage = roll_d20();
                enemy->health -= damage;
                printf("You hit the %s for %d damage!\n", enemy->tag, damage);
                printf("The %s has %d health left.\n", enemy->tag, enemy->health);
                // Statement for when the enemy reaches zero health.
                if (enemy->health <= 0) {
                    printf("\nCongratulations! You have defeated the %s.\n", enemy->tag);
                    if (strcmp(enemy->tag, "Dragon") == 0) {
                        printf("The Dragon dropped a key!\n");
                        getchar();
                        playerInventory.items[playerInventory.count].name = objs[11].description;
                        playerInventory.count++;
                        printf("You picked up the key and put it in your inventory.\n");
                    }
                    getchar();
                    enemy->location = NULL;
                }
            } else if (enemy_roll > player_roll) {
                int damage = roll_d8();
                player->health -= damage;
                printf("The %s hits you for %d damage!\n", enemy->tag, damage);
                printf("You have %d health left.\n", player->health);

                // If statement that exits the program if the player reaches zero health.
                if (player->health <= 0) {
                    printf("You have been defeated by the %s!\n", enemy->tag);
                    printf("Game over.");
                    getchar();
                    exit(0);
                }
            } else if (player_roll == enemy_roll) {
                printf("Both attacks miss!\n");
            }
        } else if (choice == 'i') {
            useItem(player, enemy);
        } else {
            printf("Invalid input. Please enter 'a' or 'i'.\n");
        }
    }
}


int roll_d20() {
    return rand() % 20 + 1;
}

int roll_d8() {
    return rand() % 8 + 1;
}

#endif //FLATLANDIA_GAME_COMBAT_H