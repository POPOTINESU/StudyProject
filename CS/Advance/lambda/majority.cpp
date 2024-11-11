#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isOdd(int n) { return n % 2 == 1; }
bool isEven(int n) { return n % 2 == 0; }

bool majority(function<bool(int)> callback, vector<int> arr) {
    int majorityCount = 0;
    for (int num : arr)
        if (callback(num)) majorityCount++;

    return majorityCount > arr.size() / 2;
}

void entry() {
    // 0か1でいい
    cout << majority(isOdd, vector<int>{1, 2, 3, 4, 5}) << endl;
    cout << majority(isOdd, vector<int>{2, 4, 6, 7, 8}) << endl;
    cout << majority(isEven, vector<int>{3, 6, 8, 12, 15}) << endl;
    cout << majority(isEven, vector<int>{1, 2, 3, 4, 5}) << endl;
}
