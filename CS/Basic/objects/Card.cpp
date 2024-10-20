#include <iostream>
#include <string>

using namespace std;

class Card
{
private:
    string suit;
    string value;
    string ingValue;

public:
    Card(string suit, string value, string intValue)
    {
        this->suit = suit;
        this->value = value;
        this->ingValue = intValue;
    }

    string getSuit()
    {
        return this->suit;
    }

    string getValue()
    {
        return this->value;
    }

    string getIntValue()
    {
        return "(" + this->ingValue + ")";
    }
};

void entry()
{
    Card *cards[4];

    cards[0] = new Card("♣", "A", "1");
    cards[1] = new Card("♦", "K", "13");
    cards[2] = new Card("♥", "Q", "12");
    cards[3] = new Card("♠", "J", "11");

    for (int i = 0; i < 4; i++)
    {
        cout << cards[i]->getSuit() << cards[i]->getValue() << cards[i]->getIntValue() << endl;
    }
}

int main()
{
    entry();
    return 0;
}