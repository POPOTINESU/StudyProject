#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string author;
    string title;
    string year;

public:
    Book(string title, string year)
    {
        this->author = "Stephen Hawkings";
        this->title = title;
        this->year = year;
    }
    string getBookInformation()
    {
        return this->title + " written by " + this->author + " in " + this->year;
    }
};

void entry()
{
    Book *books[3];

    books[0] = new Book("How Did It All Begin?", "2021");
    books[1] = new Book("The Theory of Everything", "2010");
    books[2] = new Book("God Created the Integers", "2006");

    for (int i = 0; i < 3; i++)
    {
        cout << books[i]->getBookInformation() << endl;
        delete books[i];
    }
}

int main()
{
    entry();
    return 0;
}