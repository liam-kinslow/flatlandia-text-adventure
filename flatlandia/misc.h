/* Filename: misc.h
 * Description: Header which contains miscellaneous functions.
 * Author: Liam Kinslow
 * Date: 01/05/2023
 * Input/Output: None
 * Version: 2
*/

#ifndef MAIN_C_MISC_H
#define MAIN_C_MISC_H

// Prints player health.
void playerHealth(){
    printf("You have %d health.\n", objs[10].health);
}

// Function that prints controls.
void playerControls() {
    printf("Controls:\n");
    printf("Move player: move n/e/s/w || Look around: look || Pick up item: collect\n");
    printf("List inventory items: inventory || List Controls: controls || Show health: health\n");
}

// Win condition that checks player is at start location and holds the goblet of frenchay.
void winCondition(){
    for (int i = 0; i < playerInventory.count; i++) {
        if (objs[10].location == &map[0][0] && strcmp(playerInventory.items[i].name, "The Goblet of Frenchay") == 0){
            printf("Well done! You win the game!");
            getchar();
            exit(0);
        }
    }
}

// Condition for finding and opening chest
void chestCondition(){
    for (int i = 0; i < playerInventory.count; i++) {
        if ((objs[10].location == objs[4].location) && strcmp(playerInventory.items[i].name, "Key to open treasure chest") == 0){
            printf("You find the treasure chest and open it with your key.\n");
            getchar();
            printf("Inside is the Goblet of Frenchay!\n");
            printf("You place Goblet in your inventory...\nNow you need to make it back to your ship.\n");
            playerInventory.items[playerInventory.count].name = objs[3].description;
            playerInventory.count++;
            objs[4].location = NULL;
            break;
        }
    }
}

#endif //MAIN_C_MISC_H