// Q2) Create a base class Account and derive classes SavingAccount and CurrentAccount.
// Each class must contain a minimum of 5 functions.
// Use inheritance and show all pillars of OOP.

#include <iostream>
using namespace std;

class Account
{
protected:
    string accountNumber;
    double balance;

public:
    Account(string accountNumber, double balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    virtual ~Account()
    {
        cout << "Account Destroyed" << endl;
    }

    string getAccountNumber() const
    {
        return accountNumber;
    }
    double getBalance() const
    {
        return balance;
    }
    void setAccountNumber(string accountNumber)
    {
        this->accountNumber = accountNumber;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    virtual void showDetails()
    {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }
};

class SavingAccount : public Account
{
private:
    double interestRate;
    int withdrawalLimit;

public:
    SavingAccount(string accountNumber, double balance, double interestRate, int withdrawalLimit)
        : Account(accountNumber, balance)
    {
        this->interestRate = interestRate;
        this->withdrawalLimit = withdrawalLimit;
    }

    ~SavingAccount()
    {
        cout << "SavingAccount Destroyed" << endl;
    }

    double getInterestRate() const
    {
        return interestRate;
    }

    int getWithdrawalLimit() const
    {
        return withdrawalLimit;
    }

    void setInterestRate(double interestRate)
    {
        this->interestRate = interestRate;
    }

    void setWithdrawalLimit(int withdrawalLimit)
    {
        this->withdrawalLimit = withdrawalLimit;
    }

    void showDetails() override
    {
        Account::showDetails();
        cout << "Interest Rate: " << interestRate << "%, Withdrawal Limit: " << withdrawalLimit << endl;
    }
};

class CurrentAccount : public Account
{
private:
    double overdraftLimit;
    double monthlyFee;

public:
    CurrentAccount(string accountNumber, double balance, double overdraftLimit, double monthlyFee)
        : Account(accountNumber, balance)
    {
        this->overdraftLimit = overdraftLimit;
        this->monthlyFee = monthlyFee;
    }

    ~CurrentAccount()
    {
        cout << "CurrentAccount Destroyed" << endl;
    }

    double getOverdraftLimit() const
    {
        return overdraftLimit;
    }

    double getMonthlyFee() const
    {
        return monthlyFee;
    }

    void setOverdraftLimit(double overdraftLimit)
    {
        this->overdraftLimit = overdraftLimit;
    }

    void setMonthlyFee(double monthlyFee)
    {
        this->monthlyFee = monthlyFee;
    }

    void showDetails() override
    {
        Account::showDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << ", Monthly Fee: $" << monthlyFee << endl;
    }
};

int main()
{

    Account *acc1 = new SavingAccount("SA123", 1000.0, 3.5, 5);
    Account *acc2 = new CurrentAccount("CA456", 2000.0, 500.0, 10.0);
    acc1->showDetails();
    acc2->showDetails();

    delete acc1;
    delete acc2;

    return 0;
}