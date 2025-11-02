#include <iostream>
using namespace std;

class Customer
{
    string name;
    int *data;

public:
    Customer()
    {
        cout << "Constructor called" << endl;
        name = "Ali";
        data = new int;
        *data = 100;
    }
    ~Customer()
    {
        cout << "Destructor called" << endl;
        delete data;
    }
};

int main()
{
    Customer A1;

    return 0;
}