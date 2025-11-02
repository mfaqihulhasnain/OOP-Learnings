#include <iostream>
using namespace std;
class Student {
    string name;
    int rollNo;
    string department;
public:
    void inputDetails() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore(); // clear buffer again before getline
        cout << "Enter Department: ";
        getline(cin, department);
    }
    void displayDetails() {
        cout << "\n--- Student Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Department: " << department << endl;
    }};
int main() {
    Student s1;
    s1.inputDetails();
    s1.displayDetails();
    return 0;
}
