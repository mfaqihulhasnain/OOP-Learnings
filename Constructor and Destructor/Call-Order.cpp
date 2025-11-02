#include <iostream>
using namespace std;

class Customer{
    string name;
    int* data;

    public:
    Customer(){
        name = "Unknown"; 
        cout << "Constructor called for " << name << endl;
    }
    Customer(string name){
        this->name = name;
        cout << "Constructor called for " << name << endl;
    }

    ~Customer(){
        cout << "Destructor called for " << name << endl;
    }
};

int main()
{
    Customer A1("Ali") , A2("Ahmed") , A3("Sara");
    Customer* A4 = new Customer();
    delete A4;
    return 0;
}