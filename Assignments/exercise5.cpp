#include <iostream>
using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
public:
    void GetDate() {
        char slash;
        cout << "Enter date (DD/MM/YYYY): ";
        cin >> day >> slash >> month >> slash >> year;
    }
    void displayDate() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

int main(){

    Date d;
    d.GetDate();
    cout << "Ther entered date is: ";
    d.displayDate();

    return 0;
}