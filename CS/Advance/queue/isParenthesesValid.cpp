#include <cmath>
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

bool isParenthesesPair(char key, char value) {
    map<char, char> parenthesesMap = {{'[', ']'}, {'{', '}'}, {'(', ')'}};

    if (parenthesesMap.find(key) == parenthesesMap.end() ||
        parenthesesMap[key] != value)
        return false;

    return true;
}

bool isParenthesesValid(string parentheses) {
    if (parentheses.length() % 2 == 1) return false;

    stack<char> parenthesesStack;

    for (char c : parentheses) {
        if (((parenthesesStack.empty()) && (c == ']' || c == '}' || c == ')')))
            return false;
        else if (!parenthesesStack.empty() &&
                 isParenthesesPair(parenthesesStack.top(), c)) {
            parenthesesStack.pop();
        } else
            parenthesesStack.push(c);
    }

    return parenthesesStack.empty();
}
