#include <iostream>
#include <string>

using namespace std;

class Product
{
public:
    string title;
    double price;

    Product(string title, double price)
        : title(title), price(price) {}
};

class InvoiceItem
{
public:
    Product *product;
    int quantity;
    InvoiceItem *next;

    InvoiceItem(Product *product, int quantity)
    {
        this->product = product;
        this->quantity = quantity;
        this->next = NULL;
    }

    double getTotalPrice()
    {

        return product->price * quantity;
    }
};

void entry()
{
    Product *product1 = new Product("shampoo", 10);
    Product *product2 = new Product("conditioner", 5);
    Product *product3 = new Product("tooth brush", 3);

    InvoiceItem *firstItem = new InvoiceItem(product1, 7);
    InvoiceItem *secondItem = new InvoiceItem(product2, 9);
    InvoiceItem *thirdItem = new InvoiceItem(product3, 10);

    firstItem->next = secondItem;
    secondItem->next = thirdItem;

    cout << firstItem->getTotalPrice() << endl;
    cout << secondItem->getTotalPrice() << endl;
    cout << firstItem->next->getTotalPrice() << endl;
    cout << firstItem->next->next->getTotalPrice() << endl;
    cout << firstItem->next->product->price << endl;
    cout << firstItem->next->next->product->title << endl;
}

int main()
{
    entry();
    return 0;
}