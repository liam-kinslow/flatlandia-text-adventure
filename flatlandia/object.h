/* Filename: object.h
 * Description: Header which contains items, monsters and the protagonist.
 * Author: Liam Kinslow
 * Date: 01/05/2023
 * Input/Output: None
 * Version: 3.0
*/

#ifndef FLATLANDIA_GAME_OBJECT_H
#define FLATLANDIA_GAME_OBJECT_H
#include <string.h>

// Structure containing locations and their tag
struct location {
    const char *description;
    const char *tag;
    const char *passable;
};

struct location const locs[36];

struct location const locs[36] = {
        {"on a sandy beach at the start. There is a crab nipping at your feet.",                                                             "Sandy beach (start)",              "yes"}, //0
        {"on a broken region scattered with small gray stones.",                                                                "Broken region",            "yes"}, //1
        {"on a rocky beach, you can hear the waves crashing against the shore.",                                                "Rocky beach",              "yes"}, //2
        {"next to a set of white cliffs, you'll need to walk carefully so as not to slip.",                                     "White cliffs",             "yes"}, //3
        {"next to a river heading toward the sea with a fast moving current, luckily there is a bridge.",                       "River with bridge",        "yes"}, //4
        {"at viewpoint with a small telescope, you look through it and see nothing but the vast sea.",                          "Viewpoint",                "yes"}, //5
        {"on hilly terrain strewn with strange-looking trees, thorny shrubs, and grass.",                                       "Hills with trees",         "yes"}, //6
        {"in a luscious meadow with with dairy cows chewing its grass.",                                                        "Open field",               "yes"}, //7
        {"west of a quaint village covered tiny homes of which a cacophony of noise is coming from.",                           "Outside village west",     "yes"}, //8
        {"on a flat region covered with diverse dark stones.",                                                                  "Flat land",                     "yes"}, //9
        {"next to a river that comes from the top of a large mountain in the distance",                                         "Mountain river",           "yes"}, //10
        {"in an abandonded village, it looks like no one has lived here for a long time.",                                      "Ruined Village",           "yes"}, //11
        {"by a slow moving river that ends in the sea.",                                                                        "River into the sea",       "yes"}, //12
        {"next to a river with a broken bridge that is impassable",                                                             "River with broken bridge", "no"}, //13
        {"in a quaint village. It's filled with hobbits dancing, singing, and drinking ale",                                    "Inside village",           "yes"}, //14
        {"south of a quaint village covered tiny homes of which a cacophony of noise is coming from.",                          "Outside village south",    "yes"}, //15
        {"on mountainous terrain replete with trees and pleasant-smelling grass.",                                              "Mountain with trees",      "yes"}, //16
        {"in a hilly terrain abounding with unusual colorful stones.", "Colourful hills",          "yes"}, //17
        {"on a black sand beach. It's misty and you have the feeling there is something otherworldly here.",                    "Black sand beach",         "yes"}, //18
        {"in front of a large clear lake, you can see a few locals fishing in it.",                                             "Lake",                     "yes"}, //19
        {"east of a quaint village covered tiny homes of which a cacophony of noise is coming from.",                           "Outside village east",     "yes"}, //20
        {"in a mountainous region sprinkled with dead shrubs.",                                                                 "Mountain with Shrubs",     "yes"}, //21
        {"in front of a towering icy mountain that is impossible to pass.",                                                     "Towering Mountain",        "no"}, //22
        {"west of a gate large town with white stoned houses.",                                                                 "Town gates west",          "yes"}, //23
        {"in front a large volcano. Long dormant, it won't pose any danger to you.",                                            "Volcano",                  "yes"}, //24
        {"in a small wooded area with deer, the sun is shining.",                                                               "Woods",                    "yes"}, //25
        {"in a deforested area. There are large piles of logs either side of you. A woodcutter passes by and waves hello.",     "Woodcutters",              "yes"}, //26
        {"in an ancient forest with gnarled trees that lean on one another.",                                                   "Forest",                   "yes"}, //27
        {"north of a gate large town with white stoned houses.",                                                                "Town gates north",         "yes"}, //28
        {"in the large town. It's busy with people shopping for goods and traders shouting out their wares.",                   "Inside town",              "yes"}, //29
        {"in a long valley with trees either side of you. It leads toward the ocean.",                                          "Valley",                   "yes"}, //30
        {"in front of a cliff with a sheer drop into the sea, you lose your nerve.",                              "Rocky cliffs",             "no"}, //31
        {"in front of a small house that looks a bit old-fashioned and is in poor condition. It's likely a hermit lives here.", "Hermit",                   "yes"}, //32
        {"in front of an impassable muddy bog, it's too dangerous to travel through.",                                          "Deep bog",             "no"}, //33
        {"in wet marshland that's difficult to walk through, let's hope it doesn't get worse.",                                 "Bog",                      "yes"}, //34
        {"in a harbour containing many small boats bringing in fish from the sea.",                                             "Harbour",                  "yes"}, //35
};

// Map of locations.
struct location const map[6][6] = {
        {locs[0], locs[6], locs[12], locs[18], locs[24], locs[30]},
        {locs[1], locs[7], locs[13], locs[19], locs[25],locs[31]},
        {locs[2], locs[8], locs[14], locs[20], locs[26],locs[32]},
        {locs[3], locs[9], locs[15], locs[21], locs[27], locs[33]},
        {locs[4], locs[10], locs[16], locs[22], locs[28], locs[34]},
        {locs[5], locs[11], locs[17], locs[23], locs[29], locs[35]},
};

// Structure containing items and characters.
struct objects {
    char *description;
    char *tag;
    struct location *location;
    int health;
};

struct objects objs[12];

struct objects objs[12] = {
        {"A silver sword that defeats an enemy in one hit", "Silver", &map[0][3]}, //0
        {"A round shield that heals slightly", "Shield", &map[0][0]}, //1
        {"A health potion", "Potion", &map[2][2]}, //2
        {"The Goblet of Frenchay", "Goblet", NULL}, //3
        {"a locked treasure chest", "Chest", NULL}, //4
        {"a dragon with a stocky body and translucent silver scales. It's guarding a chest nearby with the treasure you're looking for!", "Dragon", NULL, 35}, //5
        {"a tall Orc with dark green skin wearing dirty leather armor and wielding a bloody mace.", "Orc", NULL, 25}, //6
        {"a lumbering Ghoul with rotten flesh and sharp claws.", "Ghoul", NULL, 15}, //7
        {"a grey stone Gargoyle with widely spread wings and long horns on its head.", "Gargoyle", NULL, 25}, //8
        {"a short, red bearded Leprechaun dressed in green.", "Leprechaun", NULL, 15}, //9
        {"Explorer", "yourself", &map[0][0], 100}, //10
        {"Key to open treasure chest", "Key", NULL}, //11
};

// Function to check if a location is already used by another monster. If it returns true it will change the location of the monster.
bool duplicateLocation(int row, int col, int objectLocations[][2], int numObjects) {
    for (int i = 0; i < numObjects; i++) {
        if (objectLocations[i][0] == row && objectLocations[i][1] == col) {
            return true;
        }
    } // Re-runs do while loop if monster location is set on impassable location.
    if (strcmp(map[row][col].passable, "no") == 0) {
        return true;
    }
    return false;
}

// Function makes a random location for each monster and the chest then stores it in an array. It calls the duplicateLocation function to ensure the location is unique.
void objectLocations(){
    int objectLocations[6][2] = {0}; //  Array to store object locations.

    for(int i= 6; i < 10; i++) {
        int row, col;
       do { // Random row and column on map for objects on map but not start location.
           row = rand() % (6 + 1 - 1);
           col = rand() % (6 + 1 - 1);
       } while (duplicateLocation(row, col, objectLocations, i - 6) || (row == 0 && col == 0)); // Check if location is already used or if the map location is the same as the start location. Re-runs do loop if it return is true.

        objs[i].location = &map[row][col];
        objectLocations[i - 6][0] = row; // Add new location to the array.
        objectLocations[i - 6][1] = col;
    }
    // Randomize the chest location
    int chestRow, chestCol;
    do {
        chestRow = rand() % (6 + 1 - 1);
        chestCol = rand() % (6 + 1 - 1);
    } while (duplicateLocation(chestRow, chestCol, objectLocations, 4) || (chestRow == 0 && chestCol == 0));
    // Set the chest location
    objs[4].location = &map[chestRow][chestCol];
    // Find an adjacent cell for the dragon that is not already occupied by another monster
    int dragonRow = chestRow;
    int dragonCol = chestCol;
    do {
        if (rand() % 2 == 0) {
            dragonRow += rand() % 2 == 0 ? -1 : 1;
        } else {
            dragonCol += rand() % 2 == 0 ? -1 : 1;
        }
    } while (duplicateLocation(dragonRow, dragonCol, objectLocations, 5) || (dragonRow == 0 && dragonCol == 0));
    // Set the dragon location
    objs[5].location = &map[dragonRow][dragonCol];
}

#endif //FLATLANDIA_GAME_OBJECT_H