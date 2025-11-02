#include <iostream>
using namespace std;

class Customer{
    private:
    string name;
    int account_number , balance;
    public:
    Customer(string name, int account_number, int balance){
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
    }

    void deposit(int amount){
        if(amount > 0){
            balance += amount;
        }
        else{
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(int amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
        }
    }

    void display(){
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main(){

    Customer A1("Faqih" , 12345 , 1000);
    Customer A2("Ali" , 67890 , 2000);
    Customer A3("Sara" , 24680 , 3000);

    A1.deposit(500);
    A2.withdraw(1000);
    A3.display();

    return 0;
}