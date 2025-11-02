#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    void area() { cout << "This is a shape." << endl; }
};
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) { radius = r; }
    void area() { cout << "Area of Circle = " << M_PI * radius * radius << endl; }
};
class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }
    void area() { cout << "Area of Rectangle = " << length * width << endl; }
};

int main()
{
    int choice;
    cout << "Choose shape:\n1. Circle\n2. Rectangle\n";
    cin >> choice;

    if (choice == 1)
    {
        double r;
        cout << "Enter radius: ";
        cin >> r;
        Circle c(r);
        c.area();
    }
    else if (choice == 2)
    {
        double l, w;
        cout << "Enter length and width: ";
        cin >> l >> w;
        Rectangle rect(l, w);
        rect.area();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
