#include <iostream>
using namespace std;

class Complex{
    int real, img;
    public:
    Complex(int real, int img){
        this->real = real;
        this->img = img;
    }

    void display(){
        cout << real << " + " << img << "i" << endl;
    }

    Complex operator + (Complex &c){
        return Complex(real + c.real, img + c.img);
    }
};

int main(){

    Complex c1(3, 4);
    Complex c2(5, 6);
    Complex c3 = c1 + c2;

    c1.display();
    c2.display();
    c3.display();

    return 0;
}