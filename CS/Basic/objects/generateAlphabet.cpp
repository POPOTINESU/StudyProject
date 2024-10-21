#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<char> generateAlphabet(char firstAlphabet, char secondAlphabet)
{
    firstAlphabet = (char)tolower(firstAlphabet);
    secondAlphabet = (char)tolower(secondAlphabet);

    // secondの方が大きかったらsecondからカウントする
    if (firstAlphabet > secondAlphabet)
    {
        char temp = firstAlphabet;
        firstAlphabet = secondAlphabet;
        secondAlphabet = temp;
    }

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    vector<char> stopedStations;
    for (int i = firstAlphabet - 'a'; i <= secondAlphabet - 'a'; i++)
    {
        stopedStations.push_back(alphabet[i]);
    }
    return stopedStations;
}

int main()
{
    generateAlphabet('a', 'z');
    return 0;
}