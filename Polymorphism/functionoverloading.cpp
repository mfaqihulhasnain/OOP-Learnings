#include <iostream>
using namespace std;

class Area{
    public: 

    int calculateArea(int radius){
        return 3.14 * radius * radius;
    }

    int calculateArea(int length, int breadth){
        return length * breadth;
    }
};

int main(){

    Area A1;
    cout << "Area of Circle with radius 5: " << A1.calculateArea(5) << endl;
    cout << "Area of Rectangle with length 4 and breadth 6: " << A1.calculateArea(4, 6) << endl;

    return 0;
}