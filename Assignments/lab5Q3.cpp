#include <iostream>
using namespace std;

class Vehicle {
public:
    void showVehicle() {
        cout << "This is a Vehicle." << endl;
    }
};
class Car : public Vehicle {
public:
    void showCar() {
        cout << "This is a Car." << endl;
    }
};
class ElectricCar : public Car {
public:
    void showElectricCar() {
        cout << "This is an Electric Car." << endl;
    }
};

int main() {
    ElectricCar eCar;
    eCar.showVehicle();
    eCar.showCar();
    eCar.showElectricCar();
    return 0;
}
