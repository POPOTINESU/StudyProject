#include <cmath>
#include <iostream>
#include <iterator>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Item {
   public:
    int data;
    Item* next;

    Item(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
   public:
    Item* head;

    Stack() { this->head = nullptr; }

    void push(int data) {
        Item* temp = this->head;
        this->head = new Item(data);
        this->head->next = temp;
    }

    optional<int> pop() {
        if (this->head == nullptr) return std::nullopt;
        Item* temp = this->head;
        this->head = this->head->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    optional<int> peek() {
        if (this->head == nullptr) return std::nullopt;
        return this->head->data;
    }
};

vector<int> dailyStockPrice(vector<int> stocks) {
    Stack* stack = new Stack();
    Stack* memoStack = new Stack();
    vector<int> dailyPriceArray;

    for (int i = stocks.size() - 1; i >= 0; i--) {
        stack->push(stocks[i]);
    }

    while (dailyPriceArray.size() < stocks.size()) {
        int targetValue = stack->pop().value();
        int count = 0;
        bool flag = false;

        while (stack->peek().has_value()) {
            count++;
            int popValue = stack->pop().value();
            if (targetValue < popValue) {
                dailyPriceArray.push_back(count);
                memoStack->push(popValue);
                flag = true;
                break;
            }
            memoStack->push(popValue);
        }

        if (!flag) {
            dailyPriceArray.push_back(0);
        }

        while (memoStack->peek().has_value()) {
            stack->push(memoStack->pop().value());
        }
    }

    return dailyPriceArray;
}

int main() {
    vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = dailyStockPrice(stocks);

    for (int days : result) {
        cout << days << " ";
    }
    return 0;
}