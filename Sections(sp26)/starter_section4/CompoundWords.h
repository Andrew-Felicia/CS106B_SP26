#pragma once

#include "set.h"
#include "vector.h"
#include "lexicon.h"
#include <string>

Set<Vector<std::string>> splitsOf(std::string str);
bool isCompoundWord(std::string word, Lexicon& english);
