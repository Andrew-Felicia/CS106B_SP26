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
#include "set.h"
#include "vector.h"
using namespace std;

/*
 * twice (Code Writing)
 * --------------------------------------------------------
 * Write a function named twice that takes a vector of integers and returns
 * a set containing all the numbers in the vector that appear exactly twice.
 */

// Set<int> twice(Vector<int>& v) {
//     Map<int, int> counter;
//     for(int i : v) {
//         if(counter.containsKey(i)) {
//             counter[i] += 1;
//         } else {
//             counter[i] = 1;
//         }
//     }

//     Set<int> result;
//     for(int i : counter) {
//         if(counter[i] == 2) {
//             result.add(i);
//         }
//     }

//     return result;
// }

//bonus
Set<int> twice(Vector<int>& v) {
    Set<int> once;
    Set<int> twice;
    Set<int> more;

    for(int i : v) {
        if(once.contains(i)) {
            once.remove(i);
            twice.add(i);
        } else if(twice.contains(i)) {
            twice.remove(i);
            more.add(i);
        } else if(!more.contains(i)) {
            once.add(i);
        }
    }

    return twice;

}


/* * * * * Provided Tests Below This Point * * * * */
PROVIDED_TEST("Test from handout") {
    Vector<int> v = {1, 3, 1, 4, 3, 7, -2, 0, 7, -2, -2, 1};
    EXPECT_EQUAL(twice(v), {3, 7});
}

