#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int convertCardToNums(string cardString)
{
    // スート文字が3バイト(UTF-8の絵文字)であるため、4バイト目から取得
    string targetNum = cardString.substr(3);
    vector<string> cardNums = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    int cardNumber;

    for (int i = 0; i < cardNums.size(); i++)
    {
        if (targetNum == cardNums[i])
            return i + 1;
    }

    return 0;
}

int calculateTotalCards(vector<string> cards)
{
    int cardTotal = 0;
    for (int i = 0; i < cards.size(); i++)
    {
        cardTotal += convertCardToNums(cards[i]);
    }
    return cardTotal;
}

bool winnerBlackjack(vector<string> playerCards, vector<string> houseCards)
{
    int playerCardTotal = calculateTotalCards(playerCards);
    int houseCardTotal = calculateTotalCards(houseCards);

    if (playerCardTotal > 21)
        return false;

    if (houseCardTotal < 22 && houseCardTotal >= playerCardTotal)
        return false;

    return true;
}
