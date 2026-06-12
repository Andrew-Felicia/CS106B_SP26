/*
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "SimpleTest.h"
#include "grid.h"
#include "gridlocation.h"
using namespace std;

/*
 * waysToEscape (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named countWaysToEscape​ that returns the 
 * total number of ways to escape a maze, if we can only move south
 * and east at any position in the maze. The input is a grid of booleans
 * representing a maze, and a gridLocation representing where we are
 * starting from.
 */

int countWaysToEscape(Grid<bool>& maze, GridLocation location) {
    int row = maze.numRows();
    int col = maze.numCols();

    if(!maze.inBounds(location) || maze[location] == false) return 0;

    if(location.row == row - 1 && location.col == col - 1) {
        return 1;
    } else {
        return countWaysToEscape(maze, GridLocation(location.row + 1, location.col)) +
               countWaysToEscape(maze, GridLocation(location.row, location.col + 1));
    }


}


/* * * * * Provided Tests Below This Point * * * * */
PROVIDED_TEST("Test ways to escape") {
    Grid<bool> maze = {{true, true, true}, {true, true, true}};
    EXPECT_EQUAL(countWaysToEscape(maze, {0,0}), 3);

    maze = {{true, true, true}, {true, true, false}};
    EXPECT_EQUAL(countWaysToEscape(maze, {0,0}), 0);

    maze = {{true, true, true}, {true, false, true}};
    EXPECT_EQUAL(countWaysToEscape(maze, {0,0}), 1);

    maze = {{true, true, true}, {false, true, true}};
    EXPECT_EQUAL(countWaysToEscape(maze, {0,0}), 2);
}

