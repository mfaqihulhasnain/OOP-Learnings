#include <iostream>
using namespace std;

class a {
    int a;
    int b;
    int c;
};

// Empty class 
class b {

    // No members

};

int main() {

    a obj;
    cout << "Size of class a: " << sizeof(obj) << " bytes" << endl;

    b obj2;
    cout << "Size of class b: " << sizeof(obj2) << " bytes" << endl; // Empty class size is typically 1 byte in C++

    return 0;
}