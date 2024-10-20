#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

bool hasSpace(string str)
{
    return str.find(" ") != -1;
}

bool isAtmarkFirst(string str)
{
    char ATMARK = '@';
    return str[0] == ATMARK;
}

bool hasOnlyOneAtmark(string str)
{
    char ATMARK = '@';
    int atmarkCount = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ATMARK)
            atmarkCount++;

        if (atmarkCount > 1)
            return false;
    }

    return (atmarkCount == 1) ? true : false;
}

bool validDotMark(string str){
    char ATMARK = '@';
    char DOT_MARK = '.';

    int atmarkIndex =  str.find(ATMARK);

    // 条件上atmarkのindexの後ろから.を探せばいい
    int dotMarkIndex = str.substr(atmarkIndex).find(DOT_MARK);
    
    cout << atmarkIndex << endl;
    cout << dotMarkIndex << endl;

    return dotMarkIndex != -1;
}

vector<string> validEmailList(vector<string> emailList)
{
    // 完璧なバリデーションではなく下記の条件にのみ従う
    // スペースがないこと
    // 「@」を 1 つのみ含んでいること
    // 「@」の後に「.」があること
    // 「@」から始まらないこと

    vector<string> cleanEmailList;

    for (int i = 0; i < emailList.size(); i++)
    {
        string email = emailList[i];
        if (hasSpace(email))
            continue;

        if (!isAtmarkFirst(email))
            continue;

        if (!hasOnlyOneAtmark(email))
            continue;
        
        if (!validDotMark(email))
            continue;
        
        cleanEmailList.push_back(email);
    }
    
    return cleanEmailList;
}
