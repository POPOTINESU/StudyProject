#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

string loud(string text) {
    for_each(text.begin(), text.end(), [](char &c) { c = toupper(c); });
    return text;
}

string quiet(string text) {
    for_each(text.begin(), text.end(), [](char &c) { c = tolower(c); });
    return text;
}

string reverseText(string text) {
    reverse(text.begin(), text.end());
    return text;
}

string repeat(string text) { return text + " " + text; }

string getGreeting(int time) {
    if (0 <= time && time < 12) return "Good Morning ";
    if (12 <= time && time < 18) return "Good Afternoon ";
    return "Good Evening ";
}

string greet(int time, string name, function<string(string)> fn) {
    return getGreeting(time) + fn(name);
}

void entry() {
    cout << greet(1, "John", loud) << endl;
    cout << greet(2, "John", quiet) << endl;
    cout << greet(13, "John", reverseText) << endl;
    cout << greet(19, "John", repeat) << endl;
    cout << greet(13, "Leslie Emmanuel Beadon", loud) << endl;
    cout << greet(19, "Leslie Emmanuel Beadon", quiet) << endl;
    cout << greet(5, "Leslie Emmanuel Beadon", reverseText) << endl;
    cout << greet(1, "Leslie Emmanuel Beadon", repeat) << endl;
}