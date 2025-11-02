#include <iostream>
using namespace std;

class Payment{
public:
    virtual void processPayment(double amount) = 0;
    virtual void paymentDetails() = 0;
    virtual ~Payment() {}
};

class CreditCardPayment : public Payment{
public:
    void processPayment(double amount) override {
        cout << "Processing credit card payment of $" << amount << endl;
    }
    void paymentDetails() override {
        cout << "Payment method: Credit Card" << endl;
    }
};

int main(){

    Payment* payment1 = new CreditCardPayment();
    payment1->processPayment(100.0);
    payment1->paymentDetails();
    delete payment1;

    return 0;
}