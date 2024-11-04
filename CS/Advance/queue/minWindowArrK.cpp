#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> minWindowArrK(vector<int> intArr, int k) {
    if (k == 1) return intArr;

    deque<int> deque;
    vector<int> answer;

    for (int i = 0; i < k; i++) {
        while (!deque.empty() && intArr[deque.back()] >= intArr[i]) {
            deque.pop_back();
        }
        deque.push_back(i);
    }

    for (int i = k; i < intArr.size(); i++) {
        answer.push_back(intArr[deque.front()]);

        while (!deque.empty() && deque.front() <= i - k) deque.pop_front();

        while (!deque.empty() && intArr[deque.back()] >= intArr[i])
            deque.pop_back();

        deque.push_back(i);
    }

    answer.push_back(intArr[deque.front()]);

    return answer;
}