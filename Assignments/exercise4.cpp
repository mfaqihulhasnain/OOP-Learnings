#include <iostream>
using namespace std;

class Employee
{
private:
    int EmpNum;
    float Compensation;

public:
    void GetInfo()
    {
        cout << "Enter Employee Number: ";
        cin >> EmpNum;
        cout << "Enter Compensation: ";
        cin >> Compensation;
    }
    void DisplayInfo()
    {
        cout << "Employee Number: " << EmpNum << endl;
        cout << "Compensation: " << Compensation << endl;
    }
};
int main()
{
    Employee emp[3]; // Array of 3 employees

    cout << "Enter details for 3 employees:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nEmployee " << i + 1 << ":\n";
        emp[i].GetInfo();
    }
    cout << "\n--- Employee Details ---\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nEmployee " << i + 1 << ":\n";
        emp[i].DisplayInfo();
    }
    return 0;
}
