#include <iostream>
using namespace std;

class Human
{
protected:
    string name;
    int age;

public:
    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void Display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    void work()
    {
        cout << "Human is working" << endl;
    }
};

class Student : public Human
{
protected:
    int rollNo, fees;

public:
    Student(string name, int age, int rollNo, int fees) : Human(name, age)
    {
        this->rollNo = rollNo;
        this->fees = fees;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Fees: " << fees << endl;
    }
};

int main()
{

    Student A("Ali", 20, 101, 5000);
    A.display();
    A.Display();

    return 0;
}