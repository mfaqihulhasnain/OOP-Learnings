#include <iostream>
using namespace std;

class Human{
    private:
    string religion , color;
    public:
    string name;
    int age , weight;
};

class Student : protected Human{
    int rollno , fees;
    public:

    Student(string name , int age , int weight , int rollno , int fees){
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->rollno = rollno;
        this->fees = fees;
    }

    void Display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Weight : "<<weight<<endl;
        cout<<"Roll No : "<<rollno<<endl;
        cout<<"Fees : "<<fees<<endl;
    }
};


class Teacher : public Human{
    int salary , id;
};

int main(){

    Student A("ali", 20, 70, 101, 5000);
    A.Display();

    Teacher B;
    B.name = "Ahmed";
    cout << "Teacher Name: " << B.name << endl;

    return 0;
}