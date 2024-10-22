#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>

using namespace std;

vector<int> characterLocation(string commands)
{
    vector<int> location = {0, 0};

    map<char, int> moveAction = {
        {'N', 1},
        {'E', 1},
        {'W', -1},
        {'S', -1}};

    for (int i = 0; i < commands.length(); i++)
    {
        if (commands[i] == 'E' || commands[i] == 'W')
            location[0] = location[0] + moveAction[commands[i]];
        else
            location[1] = location[1] + moveAction[commands[i]];
    }
    return location;
}
int main()
{
    vector<int> answer = characterLocation("NNNN");

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}