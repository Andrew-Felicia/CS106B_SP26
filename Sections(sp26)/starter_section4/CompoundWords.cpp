#include "CompoundWords.h"
using namespace std;

Set<Vector<string>> splitsOfRec(string str, Vector<string>& chosen) {
    if(str == "") {
        return {chosen};
    } else {
        Set<Vector<string>> result;

        for(int i = 1; i <= str.size(); i++) {
            string chosen_string = str.substr(0, i);
            string remaining = str.substr(i);

            chosen.add(chosen_string);
            result += splitsOfRec(remaining, chosen);
            chosen.remove(chosen.size() - 1);
        }
        return result;
    }
}

Set<Vector<string>> splitsOf(string str) {
    Vector<string> chosen;
    return splitsOfRec(str, chosen);
}

//stack overflow
// bool isCompoundWord(string word, Lexicon& english) {
//     if(!english.contains(word)) {
//         return false;
//     }
//     if(word == "") return true;

//     for(int i = 1; i <= word.size(); i++) {
//         if(isCompoundWord(word.substr(0, i), english) && isCompoundWord(word.substr(i), english)) return true;
//     }

//     return false;
// }


//a single word will always return true;
// bool isCompoundWord(string word, Lexicon& english) {
//     if(!english.contains(word)) {
//         return false;
//     }
//     if(word == "") return true;

//     for(int i = 1; i <= word.size(); i++) {
//         if(english.contains(word.substr(0, i)) && isCompoundWord(word.substr(i), english)) return true;
//     }

//     return false;
// }


//look at the for loop in these two function below, they have a very subtle difference.
bool isCompoundWordRec(string word, Lexicon& english) {
    if(word == "") return true;

    for(int i = 1; i <= word.size(); i++) {
        if(english.contains(word.substr(0, i)) && isCompoundWordRec(word.substr(i), english)) return true;
    }
    return false;
}

bool isCompoundWord(string word, Lexicon& english) {
    if(!english.contains(word)) {
        return false;
    }

    for(int i = 1; i < word.size(); i++) {
        if(english.contains(word.substr(0, i)) && isCompoundWordRec(word.substr(i), english)) return true;
    }

    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("splitsOf works on RUBY and TOPAZ.") {
    EXPECT_EQUAL(splitsOf("RUBY"), {
                     {"R", "U", "B", "Y"},
                     {"R", "U", "BY"},
                     {"R", "UB", "Y"},
                     {"R", "UBY"},
                     {"RU", "B", "Y"},
                     {"RU", "BY"},
                     {"RUB", "Y"},
                     {"RUBY"}
                 });

    EXPECT_EQUAL(splitsOf("TOPAZ"), {
                     {"T", "O", "P", "A", "Z"},
                     {"T", "O", "P", "AZ"},
                     {"T", "O", "PA", "Z"},
                     {"T", "O", "PAZ"},
                     {"T", "OP", "A", "Z"},
                     {"T", "OP", "AZ"},
                     {"T", "OPA", "Z"},
                     {"T", "OPAZ"},
                     {"TO", "P", "A", "Z"},
                     {"TO", "P", "AZ"},
                     {"TO", "PA", "Z"},
                     {"TO", "PAZ"},
                     {"TOP", "A", "Z"},
                     {"TOP", "AZ"},
                     {"TOPA", "Z"},
                     {"TOPAZ"}
                 });
}

PROVIDED_TEST("isCompoundWord works on a restricted word list.") {
    Lexicon simple = { "abc", "ab", "bcd", "c", "cde", "def", "d", "ef", "efg", "abcdefg"};

    EXPECT(!isCompoundWord("a", simple));
    EXPECT(!isCompoundWord("ab", simple));
    EXPECT( isCompoundWord("abc", simple));
    EXPECT(!isCompoundWord("abcd", simple));
    EXPECT(!isCompoundWord("abcde", simple));
    EXPECT(!isCompoundWord("abcdef", simple));
    EXPECT( isCompoundWord("abcdefg", simple));
}

PROVIDED_TEST("isCompoundWord works on the full Lexicon.") {
    Lexicon english("res/EnglishWords.txt");

    EXPECT(!isCompoundWord("chrysanthemum", english));
    EXPECT( isCompoundWord("doorbell", english));
    EXPECT( isCompoundWord("heretofore", english));
}
