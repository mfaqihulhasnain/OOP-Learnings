#include <iostream>
using namespace std;
class Vehicle
{
public:
    virtual void move()
    {
        cout << "Vehicle is moving" << endl;
    }
};
class Car : public Vehicle
{
public:
    void move() override
    {
        cout << "Car is moving on 4 wheels" << endl;
    }
};
class Bike : public Vehicle
{
public:
    void move() override
    {
        cout << "Bike is moving on 2 wheels" << endl;
    }
};
int main()
{
    Vehicle *v1;
    Car c;
    Bike b;
    v1 = &c;
    v1->move();
    v1 = &b;
    v1->move();
    return 0;
}
