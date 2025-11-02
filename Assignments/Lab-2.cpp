#include <iostream>
using namespace std;
class Employee{
    string name;
    int id;
    int salary;
public:
    void setDetails(string empName, int empId, int empSalary) {
        name = empName;
        id = empId;
        salary = empSalary;
    }
    void displayDetails(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }};
int main(){
    Employee emp;
    emp.setDetails("Ali", 12345, 50000);
    emp.displayDetails();
    return 0;
}
