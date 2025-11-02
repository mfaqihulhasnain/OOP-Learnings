#include <iostream>
using namespace std;

class Human
{
    string name;
    int age;

public:
    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void introduce()
    {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }
};
class Student : public Human
{
    int rollNo;
    int fees;

public:
    Student(string name, int age, int rollNo, int fees) : Human(name, age)
    {
        this->rollNo = rollNo;
        this->fees = fees;
    }

    void display(){
        introduce();
        cout << "Roll No: " << rollNo << endl;
        cout << "Fees: " << fees << endl;
    }
};

class Teacher : public Human{
    int salary;
public:
    Teacher(string name, int age, int salary) : Human(name, age)
    {
        this->salary = salary;
    }

    void showSalary(){
        introduce();
        cout << "Salary: " << salary << endl;
    }
};
int main()
{

    Student S1("Alice", 20, 101, 5000);
    S1.display();

    Teacher T1("Bob", 35, 70000);
    T1.showSalary();

    return 0;
}