#include <iostream>
using namespace std;

class SmartDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void batteryStatus() = 0;
    virtual bool isOn() = 0;
    virtual void displayInfo() = 0;
    virtual ~SmartDevice() {}
};

class Smartphone : public SmartDevice
{
private:
    bool powerStatus;
    int batteryLevel;   
public:
    Smartphone() : powerStatus(false), batteryLevel(100) {}

void turnOn() override
    {
        powerStatus = true;
        cout << "Smartphone is now ON." << endl;
    }

    void turnOff() override
    {
        powerStatus = false;
        cout << "Smartphone is now OFF." << endl;
    }

    void batteryStatus() override
    {
        cout << "Smartphone battery level: " << batteryLevel << "%" << endl;
    }

    bool isOn() override
    {
        return powerStatus;
    }

    void displayInfo() override
    {
        cout << "Smartphone Info - Power Status: " << (powerStatus ? "ON" : "OFF") 
             << ", Battery Level: " << batteryLevel << "%" << endl;
    }

};

class Tablet : public SmartDevice
{
private:
    bool powerStatus;
    int batteryLevel;
public:
    Tablet() : powerStatus(false), batteryLevel(100) {}
    void turnOn() override
    {
        powerStatus = true;
        cout << "Tablet is now ON." << endl;
    }
    void turnOff() override
    {
        powerStatus = false;
        cout << "Tablet is now OFF." << endl;
    }
    void batteryStatus() override
    {
        cout << "Tablet battery level: " << batteryLevel << "%" << endl;
    }
    bool isOn() override
    {
        return powerStatus;
    }
    void displayInfo() override
    {
        cout << "Tablet Info - Power Status: " << (powerStatus ? "ON" : "OFF") 
             << ", Battery Level: " << batteryLevel << "%" << endl;
    }
};

int main()
{
    SmartDevice* myPhone = new Smartphone();
    myPhone->turnOn();
    myPhone->batteryStatus();
    myPhone->turnOff();
    myPhone->displayInfo();


    SmartDevice* myTablet = new Tablet();
    myTablet->turnOn();
    myTablet->batteryStatus();
    myTablet->turnOff();
    myTablet->displayInfo();
    
    delete myTablet;
    delete myPhone;
    return 0;
}
