#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

int convertNumber(string strNum)
{
    if (strNum == "A")
        return 14;
    if (strNum == "J")
        return 11;
    if (strNum == "Q")
        return 12;
    if (strNum == "K")
        return 13;

    return stoi(strNum);
}

map<int, int> getCardMap(vector<string> playerCards)
{
    map<int, int> cardPair;

    for (string card : playerCards)
    {
        int cardKey = convertNumber(card.substr(3));

        if (cardPair.find(cardKey) != cardPair.end())
            cardPair[cardKey]++;
        else
            cardPair[cardKey] = 1;
    }

    return cardPair;
}

int getMaxCount(map<int, int> cardMaps)
{
    int maxCount = 0;
    for (auto &card : cardMaps)
    {
        maxCount = max(maxCount, card.second);
    }

    return maxCount;
}

int getMaxCardKey(map<int, int> cardMaps, int value)
{

    int maxCardKey = 0;
    for (auto &card : cardMaps)
    {
        if (card.second == value)
            maxCardKey = max(maxCardKey, card.first);
    }
    return maxCardKey;
}

string winnerPairOfCards(vector<string> player1, vector<string> player2)
{
    map<int, int> player1CardMaps = getCardMap(player1);
    map<int, int> player2CardMaps = getCardMap(player2);

    for (int i = 0; i < player1.size(); i++)
    {
        int player1MaxCount = getMaxCount(player1CardMaps);
        int player2MaxCount = getMaxCount(player2CardMaps);
        int player1MaxCardKey = getMaxCardKey(player1CardMaps, player1MaxCount);
        int player2MaxCardKey = getMaxCardKey(player2CardMaps, player2MaxCount);

        if (player1MaxCount == player2MaxCount)
        {

            if (player1MaxCardKey != player2MaxCardKey)
                return player1MaxCardKey > player2MaxCardKey ? "player1" : "player2";
        }

        else if (player1MaxCount != player2MaxCount)
        {
            return player1MaxCount > player2MaxCount ? "player1" : "player2";
        }

        player1CardMaps[player1MaxCardKey] = 0;
        player2CardMaps[player2MaxCardKey] = 0;
    }

    return "draw";
}
