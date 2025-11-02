#include <iostream>
using namespace std;

class MathOperations {
public:
    int multiply(int a, int b) {
        return a * b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    int multiply(int a, int b, int c) {
        return a * b * c;
    }
};

int main() {
    MathOperations obj;

    int x = 3, y = 4, z = 5;
    double p = 2.5, q = 4.2;

    cout << "Multiplication of two integers: " << obj.multiply(x, y) << endl;
    cout << "Multiplication of two doubles: " << obj.multiply(p, q) << endl;
    cout << "Multiplication of three integers: " << obj.multiply(x, y, z) << endl;

    return 0;
}
