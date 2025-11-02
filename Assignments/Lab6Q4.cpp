#include <iostream>
using namespace std;

// Abstract base class
class Appliance {
public:
    // Pure virtual function
    virtual void turnOn() = 0;
};

// Derived class Fan
class Fan : public Appliance {
public:
    void turnOn() override {
        cout << "Fan is turned on and spinning." << endl;
    }
};

// Derived class Light
class Light : public Appliance {
public:
    void turnOn() override {
        cout << "Light is turned on and glowing." << endl;
    }
};

int main() {
    Appliance* a;  // Base class pointer

    Fan f;
    Light l;

    a = &f;
    a->turnOn();   // Calls Fan's implementation

    a = &l;
    a->turnOn();   // Calls Light's implementation

    return 0;
}
