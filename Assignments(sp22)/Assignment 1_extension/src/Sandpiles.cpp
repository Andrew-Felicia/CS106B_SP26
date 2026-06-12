/* File: Sandpiles.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 */
#include "Sandpiles.h"
#include "GUI/SimpleTest.h"


using namespace std;

/*
 * this function simulate dropping grain on grid, each grid cell can only hold 0,1,2,3 grain,
 * if more than 3 grain, it will flow to neibor cell(up, down, left, right), if out of bound,
 * the grain will drop on the ground.
 * @param Grid<int> world: the grid to drop grain.
 * @param int row: row coordinate of the dropping position.
 * @param int col: col coordinate of the dropping position.
 *
 * there's a demo you can run.
 *
 */

void dropSandOn(Grid<int>& world, int row, int col) {
    if(world[row][col] <= 2) {
        world[row][col] += 1;
        return;
    }

    world[row][col] = 0;

    if(world.inBounds(row - 1, col)) {
        dropSandOn(world, row - 1, col);
    }
    if(world.inBounds(row + 1, col)) {
        dropSandOn(world, row + 1, col);
    }
    if(world.inBounds(row, col - 1)) {
        dropSandOn(world, row, col - 1);
    }
    if(world.inBounds(row, col + 1)) {
        dropSandOn(world, row, col + 1);
    }
    return;

}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Dropping into an empty cell only changes that cell.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 3, 3, 3 },
        { 3, 0, 3 },
        { 3, 3, 3 }
    };
    Grid<int> after = {
        { 3, 3, 3 },
        { 3, 1, 3 },
        { 3, 3, 3 }
    };

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
}

PROVIDED_TEST("Non-chaining topples work.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 0, 0, 0 },
        { 1, 3, 1 },
        { 0, 2, 0 }
    };
    Grid<int> after = {
        { 0, 1, 0 },
        { 2, 0, 2 },
        { 0, 3, 0 }
    };

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
}

PROVIDED_TEST("Two topples chain.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 0, 0, 0, 0 },
        { 0, 3, 3, 0 },
        { 0, 0, 0, 0 }
    };
    Grid<int> after = {
        { 0, 1, 1, 0 },
        { 1, 1, 0, 1 },
        { 0, 1, 1, 0 }
    };

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */



STUDENT_TEST("Dropping into an empty cell only changes that cell.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 3, 3, 2 },
        { 2, 3, 3 },
        { 0, 2, 3 }
    };
    Grid<int> after = {
        { 1, 3, 0 },
        { 1, 0, 3 },
        { 2, 1, 1 }
    };

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
}







