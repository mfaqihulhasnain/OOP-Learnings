#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age, rollNumber;
    string grade;
    // Functions Getter and Setter
public:
    void setName(string n)
    {
        if (n.size() == 0)
        {
            cout << "Name cannot be empty." << endl;
            return;
        }
        name = n;
    }
    void getName()
    {
        cout << "Name: " << name << endl;
    }
    void setAge(int a)
    {
        if (a < 0 || a > 120)
        {
            cout << "Invalid age. Age must be between 0 and 120." << endl;
            return;
        }
        age = a;
    }
    void getAge()
    {
        cout << "Age: " << age << endl;
    }
    void setRollNumber(int r)
    {
        if (r <= 0)
        {
            cout << "Roll number must be a positive integer." << endl;
            return;
        }
        rollNumber = r;
    }
    int getRollNumber()
    {
        return rollNumber;
    }
    void setGrade(string g)
    {
        if (g != "A" && g != "B" && g != "C" && g != "D" && g != "F")
        {
            cout << "Invalid grade. Please enter a grade between A and F." << endl;
            return;
        }
        grade = g;
    }
    string getGrade(int pin)
    {
        if (pin == 1234) // Example PIN check
        {
            return grade;
        }
        return "Unauthorized access";
    }
};

int main()
{
    Student S1;
    S1.setName("Faqih");
    S1.setAge(20);
    S1.setRollNumber(101);
    S1.setGrade("A");

    cout << "Student Details:" << endl;
    S1.getName();
    S1.getAge();
    cout << "Roll Number: " << S1.getRollNumber() << endl;
    cout << "Grade: " << S1.getGrade(1234) << endl;

    return 0;
}