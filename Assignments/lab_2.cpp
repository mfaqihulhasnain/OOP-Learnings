#include <iostream>
using namespace std;
class Car
{
public:
    string brand;
    int year;

    void displayInfo()
    {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};
int main()
{
    Car myCar;
    myCar.brand = "Toyota";
    myCar.year = 2020;
    myCar.displayInfo();
    return 0;
}