#include <functional>
#include <iostream>
#include <string>

using namespace std;

function<string(int)> duplicateZero = [](int x) {
    string zero = "";
    for (int i = 0; i < x; i++) zero += "0";
    return zero;
};

void entry() {
    cout << duplicateZero(5) << endl;
    cout << duplicateZero(10) << endl;
}

int main() {
    entry();
    return 0;
}