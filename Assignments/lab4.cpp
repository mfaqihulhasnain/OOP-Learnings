#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    int roll_number;
public:
    Student(string name, int roll_number)
    {
        this->name = name;
        this->roll_number = roll_number;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_number << endl;
    }
    ~Student()
    {
        cout << "Destructor called for " << name << endl;
    }
};
int main()
{
    Student s1("Alice", 101);
    s1.display();
    return 0;
}