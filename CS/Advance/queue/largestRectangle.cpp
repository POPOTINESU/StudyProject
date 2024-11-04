#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int largestRectangle(vector<int> heights) {
    int maxRectangle = 0;
    stack<int> indices;
    heights.push_back(0);

    for (int i = 0; i < heights.size(); i++) {
        while (!indices.empty() && heights[indices.top()] > heights[i]) {
            int height = heights[indices.top()];
            indices.pop();
            int width = indices.empty() ? i : i - indices.top() - 1;
            maxRectangle = max(maxRectangle, height * width);
        }
        indices.push(i);
    }

    return maxRectangle;
}