#include <iostream>
using namespace std;

class Complex
{
public:
    float real, imag;

    void set(float r, float i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1, c2, sum, diff;
    c1.set(3.5, 2.5);
    c2.set(1.5, 1.0);

    sum = c1 + c2;
    diff = c1 - c2;
    cout << "First Complex Number: ";
    c1.display();
    cout << "Second Complex Number: ";
    c2.display();
    cout << "\nSum = ";
    sum.display();
    cout << "Difference = ";
    diff.display();

    return 0;
}
