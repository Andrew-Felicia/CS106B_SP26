#include "error.h";
#include "map.h";

using namespace std;


//normal recursive function.
// int numWaysToTile(int n) {
//     if(n < 0) {
//         error("n can't be negative!");
//     } else if(n == 0) {
//         return 0;
//     } else if(n == 1) {
//         return 1;
//     } else if(n == 2){
//         return 2;
//     } else {
//         return numWaysToTile(n - 1) + numWaysToTile(n - 2);
//     }
// }


//recursive with memorize. but inside int range.
// int numWaysToTileRec(int n, Map<int, int>& recorder) {
//     if(n < 0) {
//         error("n can't be negative!");
//     } else if(n == 0) {
//         return 0;
//     } else if(n == 1) {
//         return 1;
//     } else if(n == 2){
//         return 2;
//     } else if(recorder.containsKey(n)) {
//         return recorder.get(n);
//     } else {
//         int result = numWaysToTileRec(n - 1, recorder) + numWaysToTileRec(n - 2, recorder);
//         recorder.put(n, result);
//         return result;
//     }
// }

// int numWaysToTile(int n) {
//     Map<int, int> recorder;
//     return numWaysToTileRec(n, recorder);
// }

//recursive with memorize. but outside int range.
long long numWaysToTileRec(int n, Map<int, long long>& recorder) {
    if(n < 0) {
        error("n can't be negative!");
    } else if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else if(n == 2){
        return 2;
    } else if(recorder.containsKey(n)) {
        return recorder.get(n);
    } else {
        long long result = numWaysToTileRec(n - 1, recorder) + numWaysToTileRec(n - 2, recorder);
        recorder.put(n, result);
        return result;
    }
}

long long numWaysToTile(int n) {
    Map<int, long long> recorder;
    return numWaysToTileRec(n, recorder);
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"
PROVIDED_TEST("Examples from handout") {
    EXPECT_EQUAL(numWaysToTile(1), 1);
    EXPECT_EQUAL(numWaysToTile(2), 2);
    EXPECT_EQUAL(numWaysToTile(3), 3);
}

STUDENT_TEST("Edge case") {
    EXPECT_ERROR(numWaysToTile(-1));
}
STUDENT_TEST("More small cases") {
    EXPECT_EQUAL(numWaysToTile(4), 5);
    EXPECT_EQUAL(numWaysToTile(5), 8);
    EXPECT_EQUAL(numWaysToTile(6), 13);
}

STUDENT_TEST("Medium cases") {
    EXPECT_EQUAL(numWaysToTile(7), 21);
    EXPECT_EQUAL(numWaysToTile(8), 34);
}

STUDENT_TEST("Larger cases") {
    EXPECT_EQUAL(numWaysToTile(9), 55);
    EXPECT_EQUAL(numWaysToTile(10), 89);
}

STUDENT_TEST("Number of tilings should always be positive") {
    for (int n = 1; n <= 10; n++) {
        EXPECT(numWaysToTile(n) > 0);
    }
}

STUDENT_TEST("Larger values") {
    EXPECT_EQUAL(numWaysToTile(15), 987);
    EXPECT_EQUAL(numWaysToTile(20), 10946);
}

STUDENT_TEST("Very large values") {
    EXPECT_EQUAL(numWaysToTile(25), 121393);
    EXPECT_EQUAL(numWaysToTile(30), 1346269);
}

STUDENT_TEST("Huge values") {
    EXPECT_EQUAL(numWaysToTile(35), 14930352);
    EXPECT_EQUAL(numWaysToTile(40), 165580141);
}


STUDENT_TEST("Near int limit") {
    EXPECT_EQUAL(numWaysToTile(41), 267914296);
    EXPECT_EQUAL(numWaysToTile(42), 433494437);
    EXPECT_EQUAL(numWaysToTile(43), 701408733);
    EXPECT_EQUAL(numWaysToTile(44), 1134903170);
    EXPECT_EQUAL(numWaysToTile(45), 1836311903);
}

STUDENT_TEST("test for long long type") {
    EXPECT_EQUAL(numWaysToTile(50), 20365011074LL);
    EXPECT_EQUAL(numWaysToTile(60), 2504730781961LL);
    EXPECT_EQUAL(numWaysToTile(70), 308061521170129LL);
    EXPECT_EQUAL(numWaysToTile(80), 37889062373143906LL);
    EXPECT_EQUAL(numWaysToTile(90), 4660046610375530309LL);
}
