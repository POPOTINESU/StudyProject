#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Person
{
private:
    string firstName;
    string lastName;

public:
    Person(const string &firstName, const string &lastName)
        : firstName(firstName), lastName(lastName) {}

    string getFullName()
    {
        return firstName + " " + lastName;
    }

    string getInitial() const
    {
        return string(1, firstName[0]) + "." + string(1, lastName[0]);
    }
};

void entry()
{
    Person mike("Michael", "Johnson");

    cout << mike.getFullName() << endl;
    cout << mike.getInitial() << endl;

    Person carly("Carly", "Angelo");
    cout << carly.getFullName() << endl;
    cout << carly.getInitial() << endl;

    Person jessie("Jessie", "Raelynn");
    cout << jessie.getFullName() << endl;
    cout << jessie.getInitial() << endl;
}

int main()
{
    entry();
    return 0;
}