/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include <cctype>
#include "set.h"
#include "strlib.h"

using namespace std;

/*
 *
 * this function remove any non-constant characters, and convert them to
 * upper case.
 * for example:
 *
 *Input:  10 things I hate about you!
 *Output: THNGSHTBTY
 *
 *
 */

string onlyConnectize(string phrase) {
    if(phrase.empty()) {
        return phrase;
    }
    string first = phrase.substr(0, 1);
    Set<string> vowels = {"a", "e", "i", "o", "u"};
    if(isalpha(stringToChar(first)) && !vowels.contains(toLowerCase(first))) {
        return toUpperCase(first) + onlyConnectize(phrase.substr(1));
    } else {
        return onlyConnectize(phrase.substr(1));
    }
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
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


/*
 * test strategy.
 * 1.phrase.size = 0
 * 2.phrase.szie = 1
 * 3.phrase.size > 1
 * 4.phrase.size is huge
 *
 */

STUDENT_TEST("1.phrase.size = 0") {
    EXPECT_EQUAL(onlyConnectize(""), "");
}

STUDENT_TEST("1.phrase.size = 1") {
    EXPECT_EQUAL(onlyConnectize("a"), "");
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("e"), "");
    EXPECT_EQUAL(onlyConnectize("E"), "");
    EXPECT_EQUAL(onlyConnectize("i"), "");
    EXPECT_EQUAL(onlyConnectize("I"), "");
    EXPECT_EQUAL(onlyConnectize("o"), "");
    EXPECT_EQUAL(onlyConnectize("O"), "");
    EXPECT_EQUAL(onlyConnectize("u"), "");
    EXPECT_EQUAL(onlyConnectize("U"), "");
    EXPECT_EQUAL(onlyConnectize("x"), "X");
    EXPECT_EQUAL(onlyConnectize("y"), "Y");
    EXPECT_EQUAL(onlyConnectize("b"), "B");
    EXPECT_EQUAL(onlyConnectize("B"), "B");
    EXPECT_EQUAL(onlyConnectize("C"), "C");
    EXPECT_EQUAL(onlyConnectize("1"), "");
    EXPECT_EQUAL(onlyConnectize("."), "");
    EXPECT_EQUAL(onlyConnectize("@"), "");
    EXPECT_EQUAL(onlyConnectize("$"), "");
    EXPECT_EQUAL(onlyConnectize("/"), "");

}

STUDENT_TEST("1.phrase.size >1") {
    EXPECT_EQUAL(onlyConnectize("ae"), "");
    EXPECT_EQUAL(onlyConnectize("AE"), "");
    EXPECT_EQUAL(onlyConnectize("Ae"), "");
    EXPECT_EQUAL(onlyConnectize("aE"), "");
    EXPECT_EQUAL(onlyConnectize("aeiou"), "");
    EXPECT_EQUAL(onlyConnectize("AEIOU"), "");
    EXPECT_EQUAL(onlyConnectize("bcd"), "BCD");
    EXPECT_EQUAL(onlyConnectize("bcdfgjk"), "BCDFGJK");
    EXPECT_EQUAL(onlyConnectize("AbecdioUfgjk"), "BCDFGJK");
    EXPECT_EQUAL(onlyConnectize("bcdfgaaajk"), "BCDFGJK");
    EXPECT_EQUAL(onlyConnectize("abecadefagejake"), "BCDFGJK");
    EXPECT_EQUAL(onlyConnectize("bacedufoigeauoijeka"), "BCDFGJK");
    EXPECT_EQUAL(onlyConnectize("abacAdAfegEjikI"), "BCDFGJK");
}







