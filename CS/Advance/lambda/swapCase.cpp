#include <cctype>
#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<char> swapCase(vector<char> charList) {
    for_each(charList.begin(), charList.end(),
             [](char &c) { c = (isupper(c) ? tolower(c) : toupper(c)); });

    return charList;
}