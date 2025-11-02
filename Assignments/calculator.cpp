#include <iostream>
using namespace std;

class Calculator
{
    double num1, num2;

public:
    void input()
    {
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
    }
    void add()
    {
        cout << "Addition: " << (num1 + num2) << endl;
    }
    void subtract()
    {
        cout << "Subtraction: " << (num1 - num2) << endl;
    }
    void multiply()
    {
        cout << "Multiplication: " << (num1 * num2) << endl;
    }
    void divide()
    {
        if (num2 != 0)
            cout << "Division: " << (num1 / num2) << endl;
        else
            cout << "Error: Division by zero not allowed!" << endl;
    }
};
int main()
{
    Calculator c1, c2;
    cout << "--- Calculator 1 ---" << endl;
    c1.input();
    c1.add();
    c1.subtract();
    c1.multiply();
    c1.divide();
    
    cout << "\n--- Calculator 2 ---" << endl;
    c2.input();
    c2.add();
    c2.subtract();
    c2.multiply();
    c2.divide();
    return 0;
}
