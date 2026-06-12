/*
 * CS106B Section Handout Test Harness: Section 3
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Chase Davis for CS106B.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "SimpleTest.h"
#include "vector.h"
using namespace std;

/*
 * Win some, lose sum (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named canMakeSum that takes a
 * reference to a Vector<int> and an int target value and
 * returns true if it is possible to have some selection of
 * values from the Vector that sum to the target value.
 */

/*
 * @param values : the vector of integers.
 * @param target : the number we need to sum up inside values.
 * @return true if it is possible to have some selection of
 * values from the Vector that sum to the target value, false otherwise.
 *
 *
 */
bool canMakeSum(Vector<int>& values, int target) {
    if(target == 0) {
        return true;
    }

    // for(int i = 0; i < values.size(); i++) {
    //     return canMakeSum(values, target - values[i]) || canMakeSum(values, target);
    // }
    // //non-void function does not return a value in all control

    if(values.isEmpty()) {
        return false;
    }

    int choice = values[0];
    values.remove(0);

    bool findSum = canMakeSum(values, target) || canMakeSum(values, target - choice);

    //backTracking.
    values.insert(0, choice);

    return findSum;
}

// //SOLUTION 1
// bool canMakeSumHelper(Vector<int>& v, int target, int sumSoFar) {
//     if (v.isEmpty()) {
//         return sumSoFar == target;
//     }
//     /* Here we choose the last element in the vector.
//      * We could have chosen any element, but the last
//      * is the easiest and fastest method.
//      */
//     int choice = v[v.size() - 1];
//     v.remove(v.size() - 1);

//     bool with = canMakeSumHelper(v, target, sumSoFar + choice);
//     bool without = canMakeSumHelper(v, target, sumSoFar);

//     // And then we unchoose, by adding this back!
//     v.add(choice);

//     return with || without;
// }

// bool canMakeSum(Vector<int>& v, int target) {
//     return canMakeSumHelper(v, target, 0);
// }

// //SOLUTION 2
//     /*
//  * This solution is similar to the one above, except it uses
//  * an additional index parameter in a vector to make the choices,
//  * instead of removing from the vector like solution 1 did.
//  */
// bool canMakeSumHelper(Vector<int>& v, int target, int sumSoFar, int index) {
//     if (index >= v.size()) {
//         return sumSoFar == target;
//     }

//     // This is our choice now. Remember we can choose any element
//     // in the vector, so we choose the element at 'index'
//     int choice = v[index];

//     bool with = canMakeSumHelper(v, target, sumSoFar + choice, index + 1);
//     bool without = canMakeSumHelper(v, target, sumSoFar, index + 1);

//     // We don't have to add back, because we never removed!
//     return with || without;
// }

// bool canMakeSum(Vector<int>& v, int target) {
//     return canMakeSumHelper(v, target, 0, 0);
// }

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Positive example from handout.") {
    Vector<int> nums = {1,1,2,3,5};
    EXPECT(canMakeSum(nums, 9));
}

PROVIDED_TEST("Provided Test: Negative example from handout") {
    Vector<int> nums = {1,4,5,6};
    EXPECT(!canMakeSum(nums, 8));
}
