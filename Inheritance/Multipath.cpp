#include <iostream>
using namespace std;

class Human{
    public: 
    string name;
    void introduce(){
        cout << "Hello, my name is " << name << "." << endl;
    }
};

class Engineer : public virtual Human
{
protected:
    string specialization;

public:
    void work()
    {
        cout << "I have specialization in " << specialization << "." << endl;
    }
};

class Youtuber : public virtual Human
{
protected:
    int subscribers;

public:
    void ContentCreator()
    {
        cout << "I have " << subscribers << " subscribers." << endl;
    }
};

class CodeTeacher : public Engineer, public Youtuber
{
protected:
    int salary;

public:
    CodeTeacher(string name, string specialization, int subscribers , int salary)
    {
        this->name = name;
        this->specialization = specialization;
        this->subscribers = subscribers;
        this->salary = salary;
    }

    void showcase()
    {
        cout << "I am " << name << "." << endl;
        work();
        ContentCreator();
    }
};

int main()
{

    CodeTeacher CT1("Bob", "Software Development", 100000 , 50000);
    CT1.showcase();

    return 0;
}