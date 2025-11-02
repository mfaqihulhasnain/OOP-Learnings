#include <iostream>
#include <cstdlib> // for exit()
#include <cmath>   // for labs()
using namespace std;

class fraction
{
private:
    long num;
    long den;

public:
    fraction() : num(0), den(1) {}

    fraction(long n, long d) : num(n), den(d)
    {
        lowterms();
    }

    void getFraction()
    {
        char slash;
        cout << "Enter fraction (a/b): ";
        cin >> num >> slash >> den;
        lowterms();
    }

    void display() const
    {
        cout << num << "/" << den;
    }

    void lowterms()
    {
        long tnum, tden, temp, gcd;
        tnum = labs(num);
        tden = labs(den);
        if (tden == 0)
        {
            cout << "Illegal fraction: division by 0\n";
            exit(1);
        }
        else if (tnum == 0)
        { // check for 0/n
            num = 0;
            den = 1;
            return;
        }

        while (tnum != 0)
        {
            if (tnum < tden)
            {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }
        gcd = tden;

        num = num / gcd;
        den = den / gcd;
    }

    fraction operator+(const fraction &f) const
    {
        return fraction(num * f.den + den * f.num, den * f.den);
    }

    fraction operator-(const fraction &f) const
    {
        return fraction(num * f.den - den * f.num, den * f.den);
    }

    fraction operator*(const fraction &f) const
    {
        return fraction(num * f.num, den * f.den);
    }

    fraction operator/(const fraction &f) const
    {
        return fraction(num * f.den, den * f.num);
    }
};

int main()
{
    fraction f1, f2, result;
    char op;

    cout << "Enter first fraction: ";
    f1.getFraction();
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second fraction: ";
    f2.getFraction();

    switch (op)
    {
    case '+':
        result = f1 + f2;
        break;
    case '-':
        result = f1 - f2;
        break;
    case '*':
        result = f1 * f2;
        break;
    case '/':
        result = f1 / f2;
        break;
    default:
        cout << "Unknown operator\n";
        exit(1);
    }

    cout << "Result = ";
    result.display();
    cout << endl;

    return 0;
}
