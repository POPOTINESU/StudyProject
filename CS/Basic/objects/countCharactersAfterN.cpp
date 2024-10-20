#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

int countCharactersAfterN(vector<string> arr)
{   
    const int N_CHAR_NUMBER = 'n';
    int count = 0;

    for (int i = 0; i < arr.size(); i++){
        for (int c = 0; c < arr[i].length(); c++){
            if (arr[i][c] >= N_CHAR_NUMBER){
                count ++;
            }
        }
    }

    return count;
}

int main()
{
    vector<string> arr = {"the wood", "pecked peckers", "at the inn", "tomorrowland"};

    cout << countCharactersAfterN(arr) << endl;
}