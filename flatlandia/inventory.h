/* Filename: inventory.h
 * Description: Header which contains player inventory and related functions
 * Author: Liam Kinslow
 * Date: 03/04/2023
 * Input/Output: None
 * Version: 4
*/

#ifndef FLATLANDIA_GAME_INVENTORY_H
#define FLATLANDIA_GAME_INVENTORY_H
#include <stdio.h>
#include <string.h>
#include "object.h"

struct item {
    char *name;
};

struct inventory {
    struct item items[4];
    int count;
};

struct inventory playerInventory;

// Function to pick up an item.
void playerGetItem(char *noun){
    for (int i = 0; i < 10; i++) {
        if ((objs[10].location == objs[i].location) && (strcmp(objs[i].tag, "Chest") == 0)) {
            printf("The treasure chest is too heavy to carry!");
            return;
        }
        else if (objs[10].location == objs[i].location) {
            // Add the item to the player's inventory.
            playerInventory.items[playerInventory.count].name = objs[i].description;
            playerInventory.count++;
            // Remove the item from its location.
            objs[i].location = NULL;
            printf("You put %s in your inventory.\n", objs[i].description);
            return;
        }
        else if (i == 9){
            printf("There's nothing here to pick up.");
        }
    } return;
}

// Function for listing items in inventory.
void listInventory(char *noun) {
    if (playerInventory.count == 0){
        printf("Your inventory is empty.\n");
        return;
    }
    printf("Inventory list:\n");
    for (int i = 0; i < playerInventory.count; i++) {
        printf("%d. %s\n", i + 1, playerInventory.items[i]);
    } return;
}

// Use item function which can be called within combat.
void useItem(struct objects *player, struct objects *enemy) {
    if (playerInventory.count == 0) {
        printf("You don't have any items to use.\n");
        return;
    }
    else {
        listInventory(NULL);
        int itemIndex;
        do {
            printf("\nEnter index number to use item or 0 to exit: ");
            scanf("%d", &itemIndex);
            if (itemIndex == 0) {
                return;
            }
        } while (itemIndex < 1 || itemIndex > playerInventory.count); // Loops until the user has entered a valid input relating to an item.

        itemIndex--; // Item index minus 1 due to actual array indexing.
        struct item *item = &playerInventory.items[itemIndex];
        // Code which applies the effect of the item and then removes it from the inventory.
        if (strcmp(item->name, "A silver sword that defeats an enemy in one hit") == 0) {
            enemy->health = 0;
            printf("You defeated the %s!\n", enemy->tag);
            getchar();
            enemy->location = NULL;
            removeItem(itemIndex);
        }
        else if (strcmp(item->name, "A round shield that heals slightly") == 0) {
            player->health += 25;
            printf("You used the %s and gained 25 health.\n", item->name);
            removeItem(itemIndex);
        }
        else if (strcmp(item->name, "A health potion") == 0) {
            player->health += 50;
            printf("Your health is now: %d\n", player->health);
            printf("You used the %s and gained 50 health.\n", item->name);
            removeItem(itemIndex);
        }
        else {
            printf("You can't use that item here.\n");
        }
    }
}

// Remove the item from the player's inventory by shifting all items after it in the array.
void removeItem(int itemIndex) {
    for (int i = itemIndex; i < playerInventory.count-1; i++) {
        playerInventory.items[i] = playerInventory.items[i+1];
    }
    playerInventory.count--;
}

#endif //FLATLANDIA_GAME_INVENTORY_H