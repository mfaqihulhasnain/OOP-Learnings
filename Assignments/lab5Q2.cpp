#include <iostream>
using namespace std;

class Teacher
{
protected:
    string subject;
};

class Reasearcher
{
protected:
    string field;
};

class Professor : public Teacher, public Reasearcher
{
public:
    Professor(string subject, string field)
    {
        this->subject = subject;
        this->field = field;
    }
    void displayInfo()
    {
        cout << "Subject: " << subject << ", Field: " << field << endl;
    }
};

int main()
{
    Professor prof("Mathematics", "Algebra");
    prof.displayInfo();

    return 0;
}
