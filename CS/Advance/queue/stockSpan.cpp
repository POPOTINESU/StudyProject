#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> stockSpan(vector<int> stocks) {
    vector<int> answer;
    stack<int> stack;

    for (int i = 0; i < stocks.size(); i++) {
        int counter = 1;
        int currentValue = stocks[i];

        while (!stack.empty() && stocks[stack.top()] < currentValue) {
            counter += answer[stack.top()];
            stack.pop();
        }

        answer.push_back(counter);
        stack.push(i);
    }

    return answer;
}