#include <iostream>
using namespace std;

class Customer
{
    string name;
    int account_number;
    int balance;

public:
    // Default constructor
    Customer()
    {
        name = "Faqih";
        account_number = 2323;
        balance = 1000;
    }

    // INline Constructor
    inline Customer(string name, int account_number, int balance) : name(name), account_number(account_number), balance(balance) {}

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    Customer A1;
    Customer A2("John Doe", 1234, 5000);
    A1.display();
    A2.display();

    return 0;
}