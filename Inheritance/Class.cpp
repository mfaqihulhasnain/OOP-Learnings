#include <iostream>
using namespace std;

class Human
{
private:
    string religion, color;

protected:
    string name;
    int age, weight;
};

class Student : private Human
{
    int rollno, fees;

public:
    void fun(string n, int a, int w)
    {
        name = n;
        age = a;
        weight = w;
    }

    void Display()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Weight : " << weight << endl;
    }
};

int main()
{

    Student A;
    A.fun("ali", 20, 70);
    A.Display();

    return 0;
}