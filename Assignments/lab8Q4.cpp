#include <iostream>
using namespace std;

class Animal{
public:
    virtual void makeSound() = 0;
    virtual void move() = 0;
    virtual ~Animal() {}
};

class Dog : public Animal{
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
    void move() override {
        cout << "Runs on all fours." << endl;
    }
};

class Bird : public Animal{
public:
    void makeSound() override {
        cout << "Chirp!" << endl;
    }
    void move() override {
        cout << "Flies with wings." << endl;
    }
};

int main(){
    Animal* myDog = new Dog();
    Animal* myBird = new Bird();

    myDog->makeSound();
    myDog->move();

    myBird->makeSound();
    myBird->move();

    delete myDog;
    delete myBird;

    return 0;
}