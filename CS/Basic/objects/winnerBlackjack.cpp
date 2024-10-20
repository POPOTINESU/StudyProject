#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

int convertCardToNums(string cardString)
{
    if (cardString.length() == 3)
        return 10;
    char cardNums = cardString[1];
    if (cardNums == 'A')
        return 1;
    if (cardNums == 'J')
        return 11;
    if (cardNums == 'Q')
        return 12;
    if (cardNums == 'K')
        return 13;
    if (cardNums >= '2' && cardNums <= '9')
        return cardNums - '0';

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
    {
        return false;
    }

    if (houseCardTotal < 22 && houseCardTotal > playerCardTotal)
    {
        return false;
    }

    return true;
}
