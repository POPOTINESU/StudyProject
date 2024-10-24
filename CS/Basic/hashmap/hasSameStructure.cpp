#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

vector<string> spaceSplitStrings(string spaceInString)
{
    vector<string> splitStrings;
    
    while (!spaceInString.empty())
    {
        int end = spaceInString.find(' ');
        if (end == string::npos) {
            splitStrings.push_back(spaceInString);
            break;
        }
        
        string word = spaceInString.substr(0, end);
        splitStrings.push_back(word);
        
        spaceInString = spaceInString.substr(end + 1);
    }

    return splitStrings;
}

bool hasSameStructure(string inputChar, string wordList)
{
    map<char, string> wordPair;
    vector<string>  wordVector = spaceSplitStrings(wordList);

    if(inputChar.length() != wordVector.size())
        return false;

    for (int i = 0; i < inputChar.length(); i++){
        if(wordPair.find(inputChar[i]) == wordPair.end()){
            for (auto & m : wordPair){
                if(m.second == wordVector[i])
                    return false;
            }
            wordPair[inputChar[i]] = wordVector[i];
        }else{
            cout << wordPair[inputChar[i]] << ":" <<  wordVector[i]<<endl;
            if (wordPair[inputChar[i]] != wordVector[i]){
                return false;
            }
        }
    }

    return true;
}