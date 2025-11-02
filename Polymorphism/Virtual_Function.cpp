// Run Time Polymorphism using Virtual Functions in C++
#include <iostream>
using namespace std;

class Animal
{
public:
    // Pure virtual function
    //    virtual void sound() = 0; // Abstract class example no object can be created only pointer/reference can be used
    virtual void sound()
    {
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Animal *a = new Dog();
    Animal *b = new Cat();

    a->sound();
    b->sound();

    delete a;
    delete b;

    return 0;
}   
 