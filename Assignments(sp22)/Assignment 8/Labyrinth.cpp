#include "Labyrinth.h"
#include "map.h"

using namespace std;

bool canEscape(Map<Item, int>& isReady) {

    if(isReady.get(Item::SPELLBOOK) == 1 && isReady.get(Item::POTION) == 1 &&
        isReady.get(Item::WAND) == 1) {
        return true;
    }
    return false;
}


bool isPathToFreedom(MazeCell* start, const string& moves) {
    Map<Item, int> collection;
    collection.put(Item::SPELLBOOK, 0);
    collection.put(Item::POTION, 0);
    collection.put(Item::WAND, 0);

    if(start->whatsHere == Item::SPELLBOOK || start->whatsHere == Item::POTION || start->whatsHere == Item::WAND) {
        collection.put(start->whatsHere, 1);
    }


    for(char s : moves) {
        if(s == 'N') {
            if(start->north == nullptr) return false;
            start = start->north;
            if(start->whatsHere == Item::SPELLBOOK || start->whatsHere == Item::POTION || start->whatsHere == Item::WAND) {
                collection.put(start->whatsHere, 1);
            }
        }

        if(s == 'S') {
            if(start->south == nullptr) return false;
            start = start->south;
            if(start->whatsHere == Item::SPELLBOOK || start->whatsHere == Item::POTION || start->whatsHere == Item::WAND) {
                collection.put(start->whatsHere, 1);
            }
        }

        if(s == 'W') {
            if(start->west == nullptr) return false;
            start = start->west;
            if(start->whatsHere == Item::SPELLBOOK || start->whatsHere == Item::POTION || start->whatsHere == Item::WAND) {
                collection.put(start->whatsHere, 1);
            }
        }

        if(s == 'E') {
            if(start->east == nullptr) return false;
            start = start->east;
            if(start->whatsHere == Item::SPELLBOOK || start->whatsHere == Item::POTION || start->whatsHere == Item::WAND) {
                collection.put(start->whatsHere, 1);
            }
        }
    }

    return canEscape(collection);

}




/* * * * * * Test Cases Below This Point * * * * * */
#include "GUI/SimpleTest.h"
#include "Demos/MazeGenerator.h"

/* Optional: Add your own custom tests here! */














/* * * * * Provided Tests Below This Point * * * * */

/* Utility function to free all memory allocated for a maze. */
void deleteMaze(const Grid<MazeCell*>& maze) {
    for (auto* elem: maze) {
        delete elem;
    }
    /* Good question to ponder: why don't we write 'delete maze;'
     * rather than what's shown above?
     */
}

PROVIDED_TEST("Checks paths in the sample maze.") {
    auto maze = toMaze({"* *-W *",
                        "| |   |",
                        "*-* * *",
                        "  | | |",
                        "S *-*-*",
                        "|   | |",
                        "*-*-* P"});

    /* These paths are the ones in the handout. They all work. */
    EXPECT(isPathToFreedom(maze[2][2], "ESNWWNNEWSSESWWN"));
    EXPECT(isPathToFreedom(maze[2][2], "SWWNSEENWNNEWSSEES"));
    EXPECT(isPathToFreedom(maze[2][2], "WNNEWSSESWWNSEENES"));

    /* These paths don't work, since they don't pick up all items. */
    EXPECT(!isPathToFreedom(maze[2][2], "ESNW"));
    EXPECT(!isPathToFreedom(maze[2][2], "SWWN"));
    EXPECT(!isPathToFreedom(maze[2][2], "WNNE"));

    /* These paths don't work, since they aren't legal paths. */
    EXPECT(!isPathToFreedom(maze[2][2], "WW"));
    EXPECT(!isPathToFreedom(maze[2][2], "NN"));
    EXPECT(!isPathToFreedom(maze[2][2], "EE"));
    EXPECT(!isPathToFreedom(maze[2][2], "SS"));

    deleteMaze(maze);
}

PROVIDED_TEST("Can't walk through walls.") {
    auto maze = toMaze({"* S *",
                        "     ",
                        "W * P",
                        "     ",
                        "* * *"});

    EXPECT(!isPathToFreedom(maze[1][1], "WNEES"));
    EXPECT(!isPathToFreedom(maze[1][1], "NWSEE"));
    EXPECT(!isPathToFreedom(maze[1][1], "ENWWS"));
    EXPECT(!isPathToFreedom(maze[1][1], "SWNNEES"));

    deleteMaze(maze);
}

PROVIDED_TEST("Works when starting on an item.") {
    auto maze = toMaze({"P-S-W"});

    EXPECT(isPathToFreedom(maze[0][0], "EE"));
    EXPECT(isPathToFreedom(maze[0][1], "WEE"));
    EXPECT(isPathToFreedom(maze[0][2], "WW"));

    deleteMaze(maze);
}

