#include <iostream>
using namespace std;

class a
{
    char c;
    char d;
    int b;
    double e;
};

int main()
{

    a obj;
    cout << "Size of a: " << sizeof(obj) << " bytes" << endl;

    return 0;
}