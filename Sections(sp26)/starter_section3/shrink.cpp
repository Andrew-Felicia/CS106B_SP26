/*
 * CS106B Section Handout Test Harness: Section 3
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
#include "lexicon.h"
#include "SimpleTest.h"
#include "error.h"

using namespace std;

/*
 * Shrink Word (Code Writing)
 * --------------------------------------------------------
 * 
 * Write a function that accepts as input a string and a Lexicon, then returns a shrunk 
 * version of the string. 
 * 
 * Example: Given a string `"starter"`, we can shrink it to `"a"` through
 * these: `starter` -> `starer` (remove `t`) -> `stare` (remove `r`) -> 
 * `tare` (remove `s`) -> `are` (remove `s`) -> `ae` (remove `r`) -> `a` 
 * (remove `e`). Hence, we'll return `"a"`. Note that all the intermediate 
 * words are english words. As another example, given string `"baker"`, we 
 * can shrink it to `"bake"` through these: `baker` -> `bake` (remove `r`). 
 * We can't shrink any further because if we remove a any another letter, 
 * we can't find the resulting word in the lexicon. Hence, we'll 
 * return `"bake"`.
 */
string shrinkWord(string input, Lexicon& lex) {
    if(input.length() == 0 || !lex.contains(input)) {
        return "";
    }

    string shortestWord = input;
    for(int i = 0; i < input.length(); i++) {
        string subWord = input.substr(0, i) + input.substr(i + 1);

        string result = shrinkWord(subWord, lex);

        if(result.length() != 0 && result.length() < shortestWord.length()) {
            shortestWord = result;
        }
    }

    return shortestWord;
}

//This is very similar(yes, again!) to the fewest coins problem above.
//To shrink a word, we'd to remove a letter from the word. The question is,
//which letter should we remove? This is what our backtracking solution explores!

string shrinkWord(string input, Lexicon& lex) {
    // We can't further shrink an empty word.
    // Also, if current word we have now is not
    // an English word(i.e. it isn't contained in
    // the lexicon), that's also invalid(from the problem
    // description. )
    if (input.empty() || !lex.contains(input)) {
        return "";
    }

    string shortestWord = input;
    for (size_t i = 0; i < input.length(); i ++) {
        // Remove the letter at index i and recurse!
        string subword = input.substr(0, i) + input.substr(i + 1);
        string result = shrinkWord(subword, lex);

        // Compare the words we've generated so far to
        // our shortestWord. If our new word is smaller,
        // we have to change our shortestWord!
        // We need a special check for the empty string
        // because our base case returns "" for invalid inputs.
        if (!result.empty() && result.length() < shortestWord.length()) {
            shortestWord = result;
        }
    }
    return shortestWord;
}

static Lexicon& sharedLexicon() {
    static Lexicon lex("res/EnglishWords.txt");
    return lex;
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Examples from handout.") {
    EXPECT_EQUAL(shrinkWord("starter", sharedLexicon()), "a");
    EXPECT_EQUAL(shrinkWord("baker", sharedLexicon()), "bake");
    EXPECT_EQUAL(shrinkWord("fishpond", sharedLexicon()), "fishpond");
}