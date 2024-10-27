#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
    int item;
    Item *next;

    Item(int item)
    {
        this->item = item;
        this->next = NULL;
    }
};

class SingleList
{
public:
    Item *head;

    SingleList(Item *head)
    {
        this->head = head;
    }
};

void entry()
{
    Item *item1 = new Item(7);
    Item *item2 = new Item(99);
    Item *item3 = new Item(45);

    item1->next = item2;
    item2->next = item3;

    SingleList *numList = new SingleList(item1);

    Item *currentItem = numList->head;
    while (currentItem != NULL)
    {
        cout << currentItem->item << endl;
        currentItem = currentItem->next;
    }
}
