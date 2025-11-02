#include <iostream>
using namespace std;

class Customer
{
private:
    string name;
    int balance, accountNumber;

public:
    Customer(string name, int balance, int accountNumber)
    {
        this->name = name;
        this->balance = balance;
        this->accountNumber = accountNumber;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else
        {
            throw runtime_error("Invalid deposit amount.");
        }
    }

    void withdraw(int amount)
    {
        if (amount > balance)
        {
            throw runtime_error("Insufficient funds.");
        }
        else if (amount <= 0)
        {
            throw runtime_error("Invalid withdrawal amount.");
        }
        else
        {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        }
    }
};

int main()
{
    Customer C1("John Doe", 1000, 12345);
    try
    {
        C1.deposit(100);
        C1.withdraw(2000);
        C1.deposit(300);
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}