#include <iostream>
using namespace std;

class Engineer
{
protected:
    string specialization;

public:
    void work()
    {
        cout << "I have specialization in " << specialization << "." << endl;
    }
};

class Youtuber
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
    string name;

public:
    CodeTeacher(string name, string specialization, int subscribers)
    {
        this->name = name;
        this->specialization = specialization;
        this->subscribers = subscribers;
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

    CodeTeacher CT1("Bob", "Software Development", 100000);
    CT1.showcase();

    return 0;
}