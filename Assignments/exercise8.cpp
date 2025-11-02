#include <iostream>
using namespace std;

class Serial {
private:
    static int count;  
    int serialNum;      

public:
    Serial() {
        count++;
        serialNum = count;
    }

    void report() {
        cout << "I am object number " << serialNum << endl;
    }
};
int Serial::count = 0; 

int main() {
    Serial obj1, obj2, obj3;

    obj1.report();
    obj2.report();
    obj3.report();

    return 0;
}
