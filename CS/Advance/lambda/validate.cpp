#include <functional>
#include <iostream>
#include <string>

using namespace std;

function<bool(string)> doesNotStartWithAt = [](string email) {
    if (email.length() == 0) return false;
    return email[0] != '@';
};

function<bool(string)> doesNotHaveSpace = [](string email) {
    if (email.length() == 0) return false;
    return email.find(' ') == -1;
};
function<bool(string)> hasUppercaseAndLowercase = [](string email) {
    if (email.length() == 0) return false;

    bool hasLowerCase = false;
    bool hasUpperCase = false;

    for (char c : email) {
        if (isupper(c)) hasUpperCase = true;
        if (islower(c)) hasLowerCase = true;
        if (hasUpperCase && hasLowerCase) return true;
    }
    return false;
};

function<string(function<bool(string)>, string)> emailValidation =
    [](function<bool(string)> valid, string email) {
        return valid(email) ? "Email is correct." : "Email is not correct.";
    };

void entry() {
    cout << emailValidation(doesNotStartWithAt, "@gmail.com") << endl;
    cout << emailValidation(doesNotStartWithAt, "kkk@gmail.com") << endl;
    cout << emailValidation(doesNotHaveSpace, "Hello world") << endl;
    cout << emailValidation(doesNotHaveSpace, "Helloworld") << endl;
    cout << emailValidation(hasUppercaseAndLowercase, "hello world") << endl;
    cout << emailValidation(hasUppercaseAndLowercase, "HELLO WORLD") << endl;
    cout << emailValidation(hasUppercaseAndLowercase, "Hello world") << endl;
}

int main() {
    entry();
    return 0;
}