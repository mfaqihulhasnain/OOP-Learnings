#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class fraction {
private:
    long num, den;

public:
    fraction() : num(0), den(1) {}
    fraction(long n, long d) : num(n), den(d) {
        lowterms();
    }

    void display() const {
        cout << num << "/" << den;
    }

    void lowterms() {
        long tnum, tden, temp, gcd;
        tnum = labs(num);
        tden = labs(den);
        if (tden == 0) {
            cout << "Illegal fraction: division by 0\n";
            exit(1);
        } else if (tnum == 0) {
            num = 0; den = 1;
            return;
        }
        while (tnum != 0) {
            if (tnum < tden) {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }
        gcd = tden;
        num /= gcd;
        den /= gcd;
    }

    fraction operator * (const fraction& f) const {
        return fraction(num * f.num, den * f.den);
    }};
int main() {
    int denom;
    cout << "Enter a denominator: ";
    cin >> denom;
    cout << "\t";
    for (int i = 1; i < denom; i++) {
        fraction f(i, denom);
        f.display();
        cout << "\t";}
    cout << endl;
    for (int i = 1; i < denom; i++) {
        fraction rowFrac(i, denom);
        rowFrac.display();
        cout << "\t";
        for (int j = 1; j < denom; j++) {
            fraction colFrac(j, denom);
            fraction result = rowFrac * colFrac;
            result.display();
            cout << "\t";
        }
        cout << endl;}
    return 0;
}
