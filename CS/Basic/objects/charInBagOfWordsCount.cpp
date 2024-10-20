#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

int charInBagOfWordsCount(vector<string> bagOfWords, char keyCharacter)
{
    int charCount = 0;

    for (int i = 0; i < bagOfWords.size(); i++)
    {
        for (int c = 0; c < bagOfWords[i].length(); c++)
        {
            if (bagOfWords[i][c] == keyCharacter)
            {
                charCount++;
            }
        }
    }

    return charCount;
}