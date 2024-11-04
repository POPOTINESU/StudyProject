#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> getRoll(vector<int> diceRolls) {
    stack<int> rolls;
    for (int diceRoll : diceRolls) {
        if (!rolls.empty() && rolls.top() > diceRoll) {
            while (!rolls.empty()) {
                rolls.pop();
            }
        }
        rolls.push(diceRoll);
    }

    vector<int> lastRolls;
    while (!rolls.empty()) {
        lastRolls.insert(lastRolls.begin(), rolls.top());
        rolls.pop();
    }
    return lastRolls;
}

int getMoney(vector<int> roll) {
    const int GET_MONEY = 4;
    return roll.size() * GET_MONEY;
}

string convertRollsToString(vector<int> rolls) {
    string convertedRolls;
    for (int roll : rolls) {
        convertedRolls += to_string(roll) + ",";
    }
    return "[" + convertedRolls.substr(0, convertedRolls.length() - 1) + "]";
}

string diceStreakGamble(vector<int> player1, vector<int> player2,
                        vector<int> player3, vector<int> player4) {
    vector<vector<int>> rollsArray = {getRoll(player1), getRoll(player2),
                                      getRoll(player3), getRoll(player4)};

    int winner = 1;
    vector<int> roll = rollsArray[0];
    int totalMoney = getMoney(roll);

    for (int i = 1; i < rollsArray.size(); i++) {
        int playerMoney = getMoney(rollsArray[i]);
        if (totalMoney < playerMoney) {
            winner = i + 1;
            roll = rollsArray[i];
            totalMoney = playerMoney;
        }
    }

    return "Winner: Player " + to_string(winner) + " won $" +
           to_string(totalMoney) + " by rolling " + convertRollsToString(roll);
}