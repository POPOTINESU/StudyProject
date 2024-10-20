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
    int quantity;
    Product product;
    InvoiceItem *next;

    InvoiceItem(Product product, int quantity)
        : product(product), quantity(quantity), next(NULL) {}

    double getTotalPrice()
    {
        return product.price * quantity;
    }
};

class Invoice
{
public:
    string invoiceNumber;
    InvoiceItem *invoiceItemHead;

    Invoice(string invoiceNumber, InvoiceItem invoiceItemHead)
        : invoiceNumber(invoiceNumber), invoiceItemHead(&invoiceItemHead) {}

    double amountDue(bool taxes)
    {   
        const double TAX_RATE = 0.1;

        InvoiceItem *currentProduct = invoiceItemHead;
        double totalPrice = 0;

        while (currentProduct != NULL)
        {
            totalPrice += currentProduct->getTotalPrice();

            currentProduct = currentProduct->next;
        }
        return (taxes) ? totalPrice * (1+TAX_RATE) : totalPrice;
    }
};

void entry()
{
    Product product1("shampoo", 10);
    Product product2("conditioner", 5);
    Product product3("tooth brush", 3);

    InvoiceItem firstItem(product1, 7);
    InvoiceItem secondItem(product2, 9);
    InvoiceItem thirdItem(product3, 10);

    firstItem.next = &secondItem;
    secondItem.next = &thirdItem;

    Invoice invoice("UC1234567890", firstItem);

    cout << invoice.amountDue(false) << endl;
    cout << invoice.amountDue(true) << endl;
}

int main(){
    entry();
    return 0;
}