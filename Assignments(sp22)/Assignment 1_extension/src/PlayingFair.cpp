/* File: PlayingFair.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 */
#include "PlayingFair.h"
#include "GUI/SimpleTest.h"
#include "error.h"
using namespace std;



/*
 *
 * this function return as follows:
 * 	Order       0	Order 1	 Order 2	Order 3	  Order 4
 * A-sequence	A	AB	     ABBA	    ABBABAAB  ABBABAABBAABABBA
 * B-sequence	B	BA	     BAAB	    BAABABBA  BAABABBAABBABAAB
 *
 *
 *
 *
 * The starter code contains a demo of another property of these sequences.
 * Imagine you’re in an open field. You then read the characters of an A-sequence from left to right.
 * Whenever you read an A, you take a step forward, then rotate 60°. Every time you read a B,
 * you turn around without moving. Repeating this process gives an intricate and complex result.
 * Once your code is working, run our demo app to see what it is! The slider at the bottom controls
 * the order of the sequence.
 *
 *
 */

string aSequenceOfOrder(int n) {
    if(n < 0) {
        error("n must be non-negative!");
    } else if(n == 0) {
        return "A";
    } else {
        return aSequenceOfOrder(n - 1) + bSequenceOfOrder(n - 1);
    }
}

string bSequenceOfOrder(int n) {
    if(n < 0) {
        error("n must be non-negative!");
    } else if(n == 0) {
        return "B";
    } else {
        return bSequenceOfOrder(n - 1) + aSequenceOfOrder(n - 1);
    }
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Sequences of order 3 are correct.") {
    /* Some very basic checks. */
    EXPECT_EQUAL(aSequenceOfOrder(3), "ABBABAAB");
    EXPECT_EQUAL(bSequenceOfOrder(3), "BAABABBA");
}

PROVIDED_TEST("Only characters should be As and Bs.") {
    for (int i = 0; i < 10; i++) {
        for (char ch: aSequenceOfOrder(i)) {
            EXPECT(ch == 'A' || ch == 'B');
        }
    }
}

PROVIDED_TEST("A-sequence of positive order should have equal As and Bs.") {
    /* Exclude the sequence of order 0, which is just a single character. */
    for (int i = 1; i < 10; i++) {
        int as = 0;
        int bs = 0;
        for (char ch: aSequenceOfOrder(i)) {
            if (ch == 'A') as++;
            else bs++;
        }

        EXPECT_EQUAL(as, bs);
    }
}

PROVIDED_TEST("Triggers error on negative inputs.") {
    /* The EXPECT_ERROR macro expects the given expression to call error(). Remember that
     * you need to guard against invalid inputs.
     */
    EXPECT_ERROR(aSequenceOfOrder(-137));
    EXPECT_ERROR(bSequenceOfOrder(-137));
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

STUDENT_TEST("test for order 0") {
    EXPECT_EQUAL(aSequenceOfOrder(0), "A");
    EXPECT_EQUAL(bSequenceOfOrder(0), "B");
}

STUDENT_TEST("test for order 1") {
    EXPECT_EQUAL(aSequenceOfOrder(1), "AB");
    EXPECT_EQUAL(bSequenceOfOrder(1), "BA");
}


STUDENT_TEST("test for order 2") {
    EXPECT_EQUAL(aSequenceOfOrder(2), "ABBA");
    EXPECT_EQUAL(bSequenceOfOrder(2), "BAAB");
}








