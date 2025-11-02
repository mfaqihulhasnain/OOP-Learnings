#include <iostream>
using namespace std;

class BankAccount
{
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string accountHolder, double balance)
    {
        this->accountHolder = accountHolder;
        this->balance = balance;
    }
    void display()
    {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }
    ~BankAccount()
    {
        cout << "Account closed for " << accountHolder << endl;
    }
};

int main()
{
    BankAccount account1("Alice", 1000.0);
    account1.display();

    BankAccount account2("Bob", 1500.0);
    account2.display();
    return 0;
}