#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> primeList(int x) {
    vector<bool> isPrimeList(x + 1, true);
    isPrimeList[0] = isPrimeList[1] = false;

    for (int i = 2; i <= sqrt(x); i++) {
        if (!isPrimeList[i]) continue;

        for (int currentNum = i * i; currentNum <= x; currentNum += i) {
            isPrimeList[currentNum] = false;
        }
    }

    return isPrimeList;
}

function<bool(int)> isOdd = [](int x) { return x % 2 == 1; };

function<bool(int)> isMultipleOf3Or5 = [](int x) {
    return x % 3 == 0 || x % 5 == 0;
};

function<bool(int)> createIsPrimeFunction(const vector<bool>& primes) {
    return [&primes](int x) {
        return x >= 0 && x < primes.size() && primes[x];
    };
}

int summation(function<bool(int)> fn, int x) {
    int sum = 0;
    for (int i = 1; i <= x; i++)
        if (fn(i)) sum += i;
    return sum;
}

void entry() {
    vector<bool> primes = primeList(100);
    function<bool(int)> isPrime = createIsPrimeFunction(primes);

    cout << summation(isOdd, 3) << endl;
    cout << summation(isOdd, 10) << endl;
    cout << summation(isOdd, 25) << endl;
    cout << summation(isMultipleOf3Or5, 3) << endl;
    cout << summation(isMultipleOf3Or5, 10) << endl;
    cout << summation(isMultipleOf3Or5, 100) << endl;
    cout << summation(isPrime, 2) << endl;
    cout << summation(isPrime, 10) << endl;
    cout << summation(isPrime, 100) << endl;
}