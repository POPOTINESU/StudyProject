#include <cmath>
#include <functional>
#include <iostream>
#include <string>

using namespace std;
int cube(int n) { return pow(n, 3); }
int splitAndAdd(int n) {
    int total = 0;
    while (n != 0) {
        total += n % 10;
        n /= 10;
    }
    return total;
}

void customArray(function<int(int)> callback, const vector<int>& arr) {
    function<void(int)> printNum = [](int n) { cout << n << endl; };
    for (int num : arr) {
        printNum(callback(num));
    }
}

void entry() {
    customArray(cube, vector<int>{3, 11, 24, 31});
    customArray(splitAndAdd, vector<int>{3, 11, 24, 31});
}
