#include <iostream>
using namespace std;

// Base class
class Shape
{
public:
    // Virtual functions for runtime polymorphism
    virtual void draw()
    {
        cout << "Drawing a shape" << endl;
    }

    virtual float area()
    {
        return 0;
    }
};

// Derived class Circle
class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    void draw() override
    {
        cout << "Drawing a Circle" << endl;
    }

    float area() override
    {
        return 3.14 * radius * radius;
    }
};

// Derived class Rectangle
class Rectangle : public Shape
{
private:
    float length, width;

public:
    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }

    void draw() override
    {
        cout << "Drawing a Rectangle" << endl;
    }

    float area() override
    {
        return length * width;
    }
};

int main()
{
    // Array of base class pointers
    Shape *shapes[2];

    // Storing objects of derived classes
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    // Loop through array using runtime polymorphism
    for (int i = 0; i < 2; i++)
    {
        shapes[i]->draw();
        cout << "Area = " << shapes[i]->area() << endl;
        cout << endl;
    }

    // Free allocated memory
    delete shapes[0];
    delete shapes[1];

    return 0;
}
