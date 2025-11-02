#include <iostream>
using namespace std;

class Car
{
private:
    string brand;
    string model;

public:
    Car(string brand, string model)
    {
        this->brand = brand;
        this->model = model;
    }
    void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};

int main()
{
    Car car1("Toyota", "Corolla");
    car1.display();

    Car car2(car1); // Using copy constructor
    car2.display();
    return 0;
}
