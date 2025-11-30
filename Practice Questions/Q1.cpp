// Q1) Create a base class Device and derive classes PC, Laptop, and Mobile from it.
// Each class must contain at least 5 functions (constructor, destructor, getters, setters, showDetails).
// Use inheritance and demonstrate all pillars of OOP.

#include <iostream>
using namespace std;

class Device
{
protected:
    string brand;
    float price;

public:
    Device(string brand, float price)
    {
        this->brand = brand;
        this->price = price;
    }

    virtual ~Device()
    {
        cout << "Device Destroyed" << endl;
    }

    // Getters
    string getBrand() const
    {
        return brand;
    }

    float getPrice() const
    {
        return price;
    }

    // Setters
    void setBrand(string brand)
    {
        this->brand = brand;
    }

    void setPrice(float price)
    {
        this->price = price;
    }

    virtual void showDetails()
    {
        cout << "Brand: " << brand << ", Price: $" << price << endl;
    }
};

class PC : public Device
{
private:
    int ram;
    string processor;

public:
    PC(string brand, float price, int ram, string processor) : Device(brand, price)
    {
        this->ram = ram;
        this->processor = processor;
    }

    ~PC()
    {
        cout << "PC Destroyed" << endl;
    }

    int getRam() const
    {
        return ram;
    }

    string getProcessor() const
    {
        return processor;
    }

    void setRam(int ram)
    {
        this->ram = ram;
    }

    void setProcessor(string processor)
    {
        this->processor = processor;
    }

    void showDetails() override{
        Device::showDetails();
        cout << "RAM: " << ram << "GB, Processor: " << processor << endl;
    }
};

class Laptop : public Device
{
private:
    float weight;
    float batteryLife;
public:
    Laptop(string brand, float price, float weight, float batteryLife) : Device(brand, price)
    {
        this->weight = weight;
        this->batteryLife = batteryLife;
    }
    ~Laptop()
    {
        cout << "Laptop Destroyed" << endl;
    }
    float getWeight() const
    {
        return weight;
    }

    float getBatteryLife() const
    {
        return batteryLife;
    }

    void setWeight(float weight)
    {
        this->weight = weight;
    }

    void setBatteryLife(float batteryLife)
    {
        this->batteryLife = batteryLife;
    }

    void showDetails() override
    {
        Device::showDetails();
        cout << "Weight: " << weight << "kg, Battery Life: " << batteryLife << " hours" << endl;
    }
};

class Mobile : public Device
{
private:
    float screenSize;
    int cameraResolution;
public:
    Mobile(string brand, float price, float screenSize, int cameraResolution) : Device(brand, price)
    {
        this->screenSize = screenSize;
        this->cameraResolution = cameraResolution;
    }
    ~Mobile()
    {
        cout << "Mobile Destroyed" << endl;
    }
    float getScreenSize() const
    {
        return screenSize;
    }
    int getCameraResolution() const
    {
        return cameraResolution;
    }
    void setScreenSize(float screenSize)
    {
        this->screenSize = screenSize;
    }
    void setCameraResolution(int cameraResolution)
    {
        this->cameraResolution = cameraResolution;
    }
    void showDetails() override
    {
        Device::showDetails();
        cout << "Screen Size: " << screenSize << " inches, Camera Resolution: " << cameraResolution << " MP" << endl;
    }
};

int main()
{
    Device *d1 = new PC("Dell", 800.0, 16, "Intel i7");
    Device *d2 = new Laptop("HP", 1200.0, 2.5, 10);
    Device *d3 = new Mobile("Samsung", 600.0, 6.5, 48);

    // Polymorphism in action
    d1->showDetails();
    d2->showDetails();
    d3->showDetails();

    delete d1;
    delete d2;
    delete d3;

    return 0;
}