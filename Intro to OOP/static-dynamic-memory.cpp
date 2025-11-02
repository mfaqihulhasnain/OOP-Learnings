#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age, rollno;
    string grade;
};

int main()
{
    Student* S1 = new Student;
    (*S1).name = "John";
    S1->age = 20;
    S1->rollno = 101;
    S1->grade = "A";

    cout << "Name: " << S1->name << endl;
    cout << "Age: " << (*S1).age << endl;
    cout << "Roll No: " << S1->rollno << endl;
    cout << "Grade: " << S1->grade << endl;

    return 0;
}