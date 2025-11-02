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

    // Parameterized Constructor
    Customer(string name, int account_number, int balance)
    {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
    }

    // Constructor with two parameters
    Customer(string n, int acc_num)
    {
        name = n;
        account_number = acc_num;
        balance = 50;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }

    // Copy Constructor
    Customer(Customer &B)
    {
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }
};

int main()
{
    Customer A1;
    Customer A2("John Doe", 1234, 5000);
    Customer A3("Jane Smith", 5678);
    A1.display();
    A2.display();
    A3.display();
    Customer A4(A3);  // Copy constructor is called
    A4.display();


    // Value assignment with assignment operator
    Customer A5 = A2; // Copy constructor is called
    A5.display();
    
    return 0;
}