#include <iostream>
#include <map>
#include <string>

using namespace std;

void entry()
{
    map<string, int> priceTable = {
        {"Honda Civic", 24000},
        {"Chevrolet Traverse", 30000},
        {"Toyota Camry", 25000},
        {"Subaru Outback", 27000},
        {"Tesla X", 100000}};

    cout << priceTable["Tesla X"] << endl;
    cout << priceTable["Toyota Camry"] << endl;
    cout << priceTable["Chevrolet Traverse"] << endl;
}