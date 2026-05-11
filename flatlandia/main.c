/* Filename: Flatlandia Game
 * Description: Main code for the Flatlandia Mini CW Game.
 * Author: Liam Kinslow
 * Date: 03/04/2023
 * Input/Output: None
 * Version: 2
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "parse_and_execute.h"
#include "location.h"
#include "combat.h"
#include "misc.h"
    char input[100];
    bool getInput(void) {
    printf("\n--> ");
    return fgets(input, sizeof input, stdin) != NULL;
}

int main() {
    srand(time(NULL));
    printf("Your ship washes ashore an unknown island...\n");
    objectLocations();
    getchar();
    printf("You check your map but find no recordings of it...\n");
    getchar();
    printf("This must be the uncharted land you heard rumours of...\n");
    getchar();
    printf("You decide to explore this new land...\n");
    getchar();
    printf("Find its fabled Goblet of Frenchay...\n");
    getchar();
    printf("And return home...\n");
    getchar();
    printf("Welcome to Flatlandia!\n");
    getchar();
    playerControls();
    getchar();
    printf("You stand %s\n", locs[0].description);
    while (parse_and_execute(input) && getInput());
    printf("\nBye!\n");
    return 0;
}