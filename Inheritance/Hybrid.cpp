#include <iostream>
using namespace std;

class Student{
    public:
    void print(){
        cout << "I am a student" << endl;
    }
};

class Male {
    public:
    void print(){
        cout << "I am a male" << endl;
    }
};

class Female {
    public:
    void print(){
        cout << "I am a female" << endl;
    }
};

class Boy : public Student , public Male{
    public:
    void print(){
        cout << "I am a boy" << endl;
    }
};

class Girl : public Student , public Female{
    public:
    void print(){
        cout << "I am a girl" << endl;
    }
};



int main()
{

    Girl G1;
    G1.print();
    G1.Student::print();
    G1.Female::print();
    return 0;
}