#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int age;

public:
    void displayInfo()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Student : public Person
{
private:
    string studentID;

public:
    Student(string name, int age, string studentID)
    {
        this->name = name;
        this->age = age;
        this->studentID = studentID;
    }
    void showStudent()
    {
        displayInfo();
        cout << "Student ID: " << studentID << endl;
    }
};
int main()
{
    Student student("Alice", 20, "S12345");
    student.showStudent();
    return 0;
}