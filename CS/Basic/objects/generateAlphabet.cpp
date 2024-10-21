#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<char> generateAlphabet(char firstAlphabet, char secondAlphabet)
{
    // charのa~zの範囲に確実に収まっている前提の関数である
    int firstAlphabetNumber = (char)tolower(firstAlphabet);
    int secondAlphabetNumber = (char)tolower(secondAlphabet);

    // secondの方が大きかったらsecondからカウントする
    if (secondAlphabetNumber > firstAlphabetNumber)
    {
        firstAlphabetNumber, secondAlphabetNumber = secondAlphabetNumber, firstAlphabetNumber;
    }

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    vector<char> stopedStations;
    for (int i = firstAlphabetNumber-'a'; i <= secondAlphabetNumber-'a'; i++)
    {   
        stopedStations.push_back(alphabet[i]);
    }
    return stopedStations;
}

int main(){
    generateAlphabet('a', 'z');
    return 0;
}