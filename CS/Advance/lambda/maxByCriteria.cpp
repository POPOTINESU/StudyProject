#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool compareLength(string s1, string s2) { return s1.length() >= s2.length(); }
bool compareAsciiTotal(string s1, string s2) {
    function<int(string)> calcTotalASCII = [](string str) {
        int totalASCII = 0;
        for_each(str.begin(), str.end(),
                 [&totalASCII](char &c) { totalASCII += c; });
        return totalASCII;
    };
    return calcTotalASCII(s1) >= calcTotalASCII(s2);
}

string maxByCriteria(function<bool(string, string)> callback,
                     vector<string> str) {
    string answer = "";
    for (string &s : str) {
        if (answer == "" || callback(s, answer)) answer = s;
    }
    return answer;
}

void entry() {
    vector<string> vector1{"apple", "yumberry", "grape", "banana", "mandarin"};
    cout << maxByCriteria(compareLength, vector1) << endl;

    vector<string> vector2{"zoomzoom", "choochoo", "beepbeep", "ahhhahhh"};
    cout << maxByCriteria(compareLength, vector2) << endl;

    vector<string> vector3{"apple", "yumberry", "grape", "banana", "mandarin"};
    cout << maxByCriteria(compareAsciiTotal, vector3) << endl;

    vector<string> vector4{"zoom", "choochoo", "beepbeep", "ahhhahhh"};
    cout << maxByCriteria(compareAsciiTotal, vector4) << endl;
}
