#include <functional>
#include <iostream>
#include <string>

using namespace std;
function<int(int)> dogToHuman = [](int dogAge) {
    return 20 + (dogAge - 2) * 7;
};

function<int(int)> catToHuman = [](int catAge) {
    return 24 + (catAge - 2) * 4;
};

bool qualifiedForInsurance(function<int(int)> fn, int age) {
    const int LIMIT_AGE = 60;
    return (fn(age) <= LIMIT_AGE);
}

void entry() {
    cout << qualifiedForInsurance(dogToHuman, 7) << endl;
    cout << qualifiedForInsurance(dogToHuman, 8) << endl;
    cout << qualifiedForInsurance(catToHuman, 11) << endl;
    cout << qualifiedForInsurance(catToHuman, 12) << endl;
}

int main() {
    entry();
    return 0;
}