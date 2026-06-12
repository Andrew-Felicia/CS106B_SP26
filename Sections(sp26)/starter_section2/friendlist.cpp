/*
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "map.h"
#include "vector.h"
#include "filelib.h"
#include "strlib.h"
#include "SimpleTest.h"
#include "set.h"
using namespace std;

/*
 * Friend List (Code Write)
 * ----------------------------------
 * Write a function named friendList that takes in a file name and reads
 * friend relationships from a file and writes them to a Map.
 * friendList should return the populated Map. Friendships are bi-directional.
 * The file contains one friend relationship per line, with names separated
 * by a single space. You do not have to worry about malformed entries.
 */

Map<string, Set<string>> friendList(string filename) {
    ifstream in;

    Vector<string> lines;
    if(openFile(in, filename)) {
        lines = readLines(in);
    }

    Map<string, Set<string>> friends;
    for(string line : lines) {
        Vector<string> tmp = stringSplit(line, " ");
        string friend1 = tmp[0];
        string friend2 = tmp[1];
        friends[friend1].add(friend2);
        friends[friend2].add(friend1);
    }

    return friends;
}

// Set<string> mutualList(Map<string, Set<string> >& friendList, string friend1, string friend2) {
//     Set<string> result;
//     for(string i : friendList) {
//         if(friendList[i].contains(friend1) && friendList[i].contains(friend2)) {
//             result.add(i);
//         }
//     }
//     return result;
// }

Set<string> mutualList(Map<string, Set<string> >& friendList, string friend1, string friend2) {
    return friendList[friend1] * friendList[friend2];
}
///* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("provided test case from handout for friendList") {
    Map<string, Set<string>> soln;
    soln["Abby"] = {"Barney", "Clyde"};
    soln["Barney"] = {"Abby"};
    soln["Clyde"] = {"Abby"};
    EXPECT_EQUAL(soln, friendList("res/buddies.txt"));
}

PROVIDED_TEST("provided test case from handout for mutualList") {
    Map<string, Set<string>> friendList;
    friendList["Abby"] = {"Barney", "Clyde"};
    friendList["Barney"] = {"Abby"};
    friendList["Clyde"] = {"Abby"};
    EXPECT_EQUAL(mutualList(friendList, "Barney", "Clyde"), {"Abby"});
    EXPECT_EQUAL(mutualList(friendList, "Barney", "Abby"), {});
}
