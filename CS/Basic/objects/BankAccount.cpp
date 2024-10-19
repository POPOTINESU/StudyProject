#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class BankAccount
{
private:
    string bankName;
    string ownerName;
    int savings;

public:
    BankAccount(string bankName, string ownerName, int savings)
        : bankName(bankName), ownerName(ownerName), savings(savings) {}

    int depositMoney(int depositAmount)
    {
        int commission = (savings <= 20000) ? 100 : 0;

        savings += depositAmount - commission;

        return savings;
    }

    int withdrawMoney(int withdrawAmount)
    {
        double MAX_WITHDRAW_RATE = 0.2;
        int MAX_WITHDRAW_AMOUNT = savings * MAX_WITHDRAW_RATE;

        int amount = (withdrawAmount > MAX_WITHDRAW_AMOUNT) ? MAX_WITHDRAW_AMOUNT : withdrawAmount;

        savings -= amount;

        return savings;
    }

    double pastime(int days)
    {
        double TRANSFER_AMOUNT_PER_DAYS = 0.25;
        return savings + TRANSFER_AMOUNT_PER_DAYS * days;
    }
};

void entry()
{
    BankAccount user1("Chase", "Claire Simmmons", 30000);
    cout << user1.withdrawMoney(2000) << endl;
    cout << user1.depositMoney(10000) << endl;
    cout << fixed << setprecision(2) << user1.pastime(93) << endl;

    BankAccount user2("Bank Of America", "Remy Clay", 10000);
    cout << user2.withdrawMoney(5000) << endl;
    cout << user2.depositMoney(12000) << endl;
    cout << fixed << setprecision(2) << user2.pastime(505) << endl;
}

int main()
{
    entry();
    return 0;
}