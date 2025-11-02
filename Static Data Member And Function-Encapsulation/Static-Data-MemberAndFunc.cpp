#include <iostream>
using namespace std;

class Customer
{
private:
    string name;
    int account_number, balance;
    static int total_customers;
    static int total_balance;

public:
    Customer(string name, int account_number, int balance)
    {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        total_customers++;
        total_balance += balance;
    }

    static void AccessStatic()
    {
        cout << "Total Customers (Static): " << total_customers << endl;
        cout << "Total Balance (Static): " << total_balance << endl;
    }

    void Deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            total_balance += amount;
        }
    }

    void Withdraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            total_balance -= amount;
        }
    }

    void Display()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
        cout << "Total Customers: " << total_customers << endl;
    }

    void ShowTotalCustomers()
    {
        cout << "Total Customers: " << total_customers << endl;
    }
};

int Customer::total_customers = 0;
int Customer::total_balance = 0;

int main()
{
    Customer customer1("John Doe", 12345, 1000);
    Customer customer2("Jane Smith", 67890, 2000);
    Customer customer3("Alice Johnson", 13579, 3000);
    Customer::AccessStatic();
    customer1.Deposit(500);
    customer2.Withdraw(1000);
    Customer::AccessStatic();

    return 0;
}