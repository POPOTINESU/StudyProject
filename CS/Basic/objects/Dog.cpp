#include <iostream>
#include <string>
using namespace std;

class Dog
{
private:
    string name;
    int size;
    int age;

public:
    Dog(const string &name, const int &size, const int &age)
        : name(name), size(size), age(age) {}

    string bark() const
    {
        if (size >= 50)
            return "Wooof! Woof!";
        else if (size >= 20)
            return "Ruff! Ruff!";
        else
            return "Yip! Yip!";
    }

    int calcHumanAge() const
    {
        return 12 + (age - 1) * 7;
    }
};

void entry()
{
    Dog goldenRetriever("Golden Retriever", 60, 10);

    cout << goldenRetriever.bark() << endl;
    cout << goldenRetriever.calcHumanAge() << endl;

    Dog siberianHusky("Siberian Husky", 55, 6);
    cout << siberianHusky.bark() << endl;
    cout << siberianHusky.calcHumanAge() << endl;

    Dog poodle("poodle", 10, 1);
    cout << poodle.bark() << endl;
    cout << poodle.calcHumanAge() << endl;

    Dog shibaInu("shibaInu", 35, 4);
    cout << shibaInu.bark() << endl;
    cout << shibaInu.calcHumanAge() << endl;
}

int main()
{
    entry();

    return 0;
}