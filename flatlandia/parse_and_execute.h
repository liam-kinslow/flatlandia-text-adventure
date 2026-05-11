/* Filename: parse_and_execute.h
 * Description: Function that reads a written command and executes it.
 * Author: Liam Kinslow
 * Date: 01/05/2023
 * Input/Output: None
 * Version: 2.0
*/
#include <string.h>
#include "inventory.h"
#include "location.h"
#include "misc.h"

#ifndef FLATLANDIA_GAME_PARSE_AND_EXECUTE_H
#define FLATLANDIA_GAME_PARSE_AND_EXECUTE_H

bool parse_and_execute(char *command) {
    /* strtok breaks a string into small tokens with new line being its
     * separation point set by the delimiter. */
    char *verb = strtok(command, " \n");
    char *noun = strtok(NULL, " \n");
    if (verb != NULL)
    {
        // strcmp is comparing two strings and running the statement if they're the same (== 0).
        if (strcmp(verb, "quit") == 0) // Quit game.
        {
            return false;
        }
        else if (strcmp(verb, "move") == 0) // Move player
        {
            if (noun != NULL) {
                playerMove(noun);
            } else {
                printf("You need to provide a direction to move.\n");
            }
        }
        else if (strcmp(verb, "look") == 0) // Look at surroundings and items.
        {
            playerLook(noun);
        }
        else if (strcmp(verb, "collect") == 0) // Collect item at location.
        {
            playerGetItem(noun);
        }
        else if (strcmp(verb, "inventory") == 0) // List inventory items.
        {
            listInventory(noun);
        }
        else if (strcmp(verb, "health") == 0) // Show player health.
        {
            playerHealth();
        }
        else if (strcmp(verb, "controls") == 0) // Show controls.
        {
            playerControls();
        }
        else
        {
            printf("I don't know how to '%s'.\n", verb); // Unknown command.
        }
    }
    return true;
}
#endif //FLATLANDIA_GAME_PARSE_AND_EXECUTE_H