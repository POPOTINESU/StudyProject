#include <functional>
#include <iostream>
#include <string>

using namespace std;

int entry() {
    function<string(int)> fizzBuzz = [](int x) {
        string str = "";
        for (int i = 1; i <= x; i++) {
            if (i % 15 == 0)
                str += "FizzBuzz-";
            else if (i % 3 == 0)
                str += "Fizz-";
            else if (i % 5 == 0)
                str += "Buzz-";
            else
                str += to_string(i) + "-";
        }
        return str.substr(0, str.length() - 1);
    };

    cout << fizzBuzz(9) << endl;
    cout << fizzBuzz(20) << endl;

    return 0;
}

int main() {
    entry();
    return 0;
}