#include <iostream>
using namespace std;

class Person{
    public:
    virtual void introduce() = 0;
    virtual void proffesion() = 0;
    virtual ~Person() {}
};

class Student : public Person {
    void introduce() override {
        cout << "I am a student." << endl;
    }
    void proffesion() override {
        cout << "My proffesion is studying." << endl;
    }
};

class Teacher : public Person {
    void introduce() override {
        cout << "I am a teacher." << endl;
    }
    void proffesion() override {
        cout << "My proffesion is teaching." << endl;
    }
};

int main(){

    Person* p1 = new Student();
    Person* p2 = new Teacher();

    p1->introduce();
    p1->proffesion();

    p2->introduce();
    p2->proffesion();

    delete p1;
    delete p2;

    return 0;
}