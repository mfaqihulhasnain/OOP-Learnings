#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width)
    {
        this->length = length;
        this->width = width;
    }
    double area()
    {
        return length * width;
    }
};

int main()
{
    Rectangle rect(10.5, 5.5);
    cout << "Area of Rectangle: " << rect.area() << endl;
    return 0;
}