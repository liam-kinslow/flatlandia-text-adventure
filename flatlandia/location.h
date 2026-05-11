/* Filename: location.h
 * Description: Header that contains the locations of the game.
 * Author: Liam Kinslow
 * Date: 01/04/2023
 * Input/Output: None
 * Version: 3.0
*/
#ifndef FLATLANDIA_GAME_LOCATION_H
#define FLATLANDIA_GAME_LOCATION_H
#include <stdlib.h>
#include "object.h"

// Function to move player one step north, east, south or west.
void playerMove(char *noun) {
    struct objects *player = &objs[10];
    // code finds the row and column of the player on the map.
    int row, col;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (player->location == &map[i][j]) {
                row = i;
                col = j;
                break;
            }
        }
    }
    // Direction of movement is passed through to switch statement and checked against 4 cases.
    switch (*noun) {
        case 'n':
            if (row > 0) {
                struct location *new_location = &map[row - 1][col];
                if (strcmp(new_location->passable, "yes") == 0) {
                    player->location = new_location;
                    winCondition();
                    printf("You stand %s \n", player->location->description);
                    enemy_collision();
                    chestCondition();
                } else {
                    printf("You stand %s You decide to turn back.\n", new_location->description);
                }
            } else {
                printf("You cannot move into the sea!\n");
            }
            break;
        case 'e':
            if (col < 5) {
                struct location *new_location = &map[row][col + 1];
                if (strcmp(new_location->passable, "yes") == 0) {
                    player->location = new_location;
                    winCondition();
                    printf("You stand %s \n", player->location->description);
                    enemy_collision();
                    chestCondition();
                } else {
                    printf("You stand %s You decide to turn back.\n", new_location->description);
                }
            } else {
                printf("You cannot move into the sea!\n");
            }
            break;
        case 's':
            if (row < 5) {
                struct location *new_location = &map[row + 1][col];
                if (strcmp(new_location->passable, "yes") == 0) {
                    player->location = new_location;
                    winCondition();
                    printf("You stand %s \n", player->location->description);
                    enemy_collision();
                    chestCondition();
                } else {
                    printf("You stand %s You decide to turn back.\n", new_location->description);
                }
            } else {
                printf("You cannot move into the sea!\n");
            }
            break;
        case 'w':
            if (col > 0) {
                struct location *new_location = &map[row][col - 1];
                if (strcmp(new_location->passable, "yes") == 0) {
                    player->location = new_location;
                    winCondition();
                    printf("You stand %s \n", player->location->description);
                    enemy_collision();
                    chestCondition();
                } else {
                    printf("You stand %s You decide to turn back.\n", new_location->description);
                }
            } else {
                printf("You cannot move into the sea!\n");
            }
            break;
        default:
            printf("Invalid direction. Enter n, e, s, or w.\n");
            return;
    }
}

// Function to examine the location for items and send the player the tag of the nearby map locations.
void playerLook(char *noun) {
    // Code finds the row and column of the player on the map.
    struct objects *player = &objs[10];
    int row, col;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (player->location == &map[i][j]) {
                row = i;
                col = j;
                break;
            }
        }
    }
    // Prints the player location tag.
    printf("You are at %s\n", player->location->tag),
            // If the condition is true ? print tag of map location : otherwise print this.
            printf("To the north: %s\n", row > 0 ? map[row-1][col].tag : "Nothing but the sea!");
    printf("To the east: %s\n", col < 5 ? map[row][col+1].tag : "Nothing but the sea!");
    printf("To the south: %s\n", row < 5 ? map[row+1][col].tag : "Nothing but the sea!");
    printf("To the west: %s\n", col > 0 ? map[row][col-1].tag : "Nothing but the sea!");
    // Loops through the objects to print any items at player location.
    for (int i = 0; i < 10; i++) {
        if (objs[10].location == objs[i].location) {
            printf("\nYou find %s\n", objs[i].description);
            break;
        } else if (i == 9){
            printf("\nThere are no items at your current location.");
        }
    } return;
}

#endif //FLATLANDIA_GAME_LOCATION_H