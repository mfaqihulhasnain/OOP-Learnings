#include <iostream>
#include <string>
using namespace std;

// Date class
class Date {
private:
    int day, month, year;

public:
    void getDate() {
        cout << "Enter hire date (dd mm yyyy): ";
        cin >> day >> month >> year;
    }

    void showDate() const {
        cout << day << "/" << month << "/" << year;
    }
};

// Enum for employee type
enum etype { laborer, secretary, manager, accountant, executive, researcher };

class Employee {
private:
    int EmpNum;
    float Compensation;
    Date hireDate;   // object of Date class
    etype EmpType;   // enum variable

public:
    void getemploy() {
        cout << "Enter Employee Number: ";
        cin >> EmpNum;
        cout << "Enter Compensation: ";
        cin >> Compensation;

        hireDate.getDate();

        char type;
        cout << "Enter employee type (l=Laborer, s=Secretary, m=Manager, "
                "a=Accountant, e=Executive, r=Researcher): ";
        cin >> type;

        switch(type) {
            case 'l': EmpType = laborer; break;
            case 's': EmpType = secretary; break;
            case 'm': EmpType = manager; break;
            case 'a': EmpType = accountant; break;
            case 'e': EmpType = executive; break;
            case 'r': EmpType = researcher; break;
            default: cout << "Invalid type! Defaulting to laborer.\n";
                     EmpType = laborer;
        }
    }

    void putemploy() const {
        cout << "\nEmployee Number: " << EmpNum
             << "\nCompensation: " << Compensation
             << "\nHire Date: ";
        hireDate.showDate();

        cout << "\nEmployee Type: ";
        switch(EmpType) {
            case laborer:   cout << "Laborer"; break;
            case secretary: cout << "Secretary"; break;
            case manager:   cout << "Manager"; break;
            case accountant:cout << "Accountant"; break;
            case executive: cout << "Executive"; break;
            case researcher:cout << "Researcher"; break;
        }
        cout << endl;
    }
};

int main() {
    Employee emp[3];

    cout << "Enter details for 3 employees:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        emp[i].getemploy();
    }

    cout << "\n--- Employee Details ---\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        emp[i].putemploy();
    }

    return 0;
}
