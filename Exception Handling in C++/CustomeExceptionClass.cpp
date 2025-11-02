#include <iostream>
using namespace std;

class InvalidAmountError : public runtime_error
{
public:
    InvalidAmountError(const string &msg) : runtime_error(msg) {};
};

class InsufficientFundsError : public runtime_error
{
public:
    InsufficientFundsError(const string &msg) : runtime_error(msg) {};
};

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
            throw InvalidAmountError("Invalid deposit amount.");
        }
    }

    void withdraw(int amount)
    {
        if (amount > balance)
        {
            throw InsufficientFundsError("Insufficient funds.");
        }
        else if (amount <= 0)
        {
            throw InvalidAmountError("Invalid withdrawal amount.");
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
    catch (const InvalidAmountError &e)
    {
        cerr << e.what() << endl;
    }
    catch (const InsufficientFundsError &e)
    {
        cerr << e.what() << endl;
    }
    catch (...)
    {
        cerr << "An unexpected error occurred." << endl;
    }
    return 0;
}