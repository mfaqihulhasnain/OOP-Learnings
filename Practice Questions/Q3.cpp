#include <iostream>
using namespace std;

// ================= Base Class =================
class Employee
{
protected:
    string name;
    int id;
    float salary;

public:
    Employee(string name, int id, float salary)
    {
        this->name = name;
        this->id = id;
        this->salary = salary;
    }

    virtual ~Employee()
    {
        cout << "Employee Destroyed" << endl;
    }

    // Getters
    string getName() const { return name; }
    int getId() const { return id; }
    float getSalary() const { return salary; }

    // Setters
    void setName(string name) { this->name = name; }
    void setId(int id) { this->id = id; }
    void setSalary(float salary) { this->salary = salary; }

    virtual void displayInfo()
    {
        cout << "Name: " << name
             << ", ID: " << id
             << ", Salary: $" << salary << endl;
    }
};

// ================= Manager Class =================
class Manager : public Employee
{
private:
    string department;
    int teamSize;

public:
    Manager(string name, int id, float salary, string department, int teamSize)
        : Employee(name, id, salary)
    {
        this->department = department;
        this->teamSize = teamSize;
    }

    ~Manager()
    {
        cout << "Manager Destroyed" << endl;
    }

    // Getters & Setters
    string getDepartment() const { return department; }
    int getTeamSize() const { return teamSize; }

    void setDepartment(string dept) { department = dept; }
    void setTeamSize(int size) { teamSize = size; }

    void displayInfo() override
    {
        Employee::displayInfo();
        cout << "Department: " << department
             << ", Team Size: " << teamSize << endl;
    }

    void conductMeeting()
    {
        cout << name << " is conducting a meeting." << endl;
    }

    void evaluatePerformance()
    {
        cout << name << " is evaluating team performance." << endl;
    }

    void allocateBudget()
    {
        cout << name << " is allocating budget." << endl;
    }
};

// ================= Developer Class =================
class Developer : public Employee
{
private:
    string programmingLanguage;
    int experienceYears;

public:
    Developer(string name, int id, float salary, string programmingLanguage, int experienceYears)
        : Employee(name, id, salary)
    {
        this->programmingLanguage = programmingLanguage;
        this->experienceYears = experienceYears;
    }

    ~Developer()
    {
        cout << "Developer Destroyed" << endl;
    }

    // Getters & Setters
    string getLanguage() const { return programmingLanguage; }
    int getExperience() const { return experienceYears; }

    void setLanguage(string lang) { programmingLanguage = lang; }
    void setExperience(int exp) { experienceYears = exp; }

    void displayInfo() override
    {
        Employee::displayInfo();
        cout << "Programming Language: " << programmingLanguage
             << ", Experience: " << experienceYears << " years" << endl;
    }

    void writeCode()
    {
        cout << name << " is writing code in " << programmingLanguage << endl;
    }

    void debugCode()
    {
        cout << name << " is debugging code." << endl;
    }

    void attendTraining()
    {
        cout << name << " is attending training." << endl;
    }
};

// ================= Intern Class =================
class Intern : public Employee
{
private:
    string university;
    int durationMonths;

public:
    Intern(string name, int id, float salary, string university, int durationMonths)
        : Employee(name, id, salary)
    {
        this->university = university;
        this->durationMonths = durationMonths;
    }

    ~Intern()
    {
        cout << "Intern Destroyed" << endl;
    }

    // Getters & Setters
    string getUniversity() const { return university; }
    int getDuration() const { return durationMonths; }

    void setUniversity(string uni) { university = uni; }
    void setDuration(int months) { durationMonths = months; }

    void displayInfo() override
    {
        Employee::displayInfo();
        cout << "University: " << university
             << ", Duration: " << durationMonths << " months" << endl;
    }

    void attendOrientation()
    {
        cout << name << " is attending orientation." << endl;
    }

    void submitReport()
    {
        cout << name << " is submitting report." << endl;
    }

    void requestExtension()
    {
        cout << name << " is requesting internship extension." << endl;
    }
};

// ================= Main =================
int main()
{

    Employee *e1 = new Manager("Ali", 101, 90000, "IT", 10);
    Employee *e2 = new Developer("Sara", 102, 70000, "C++", 3);
    Employee *e3 = new Intern("Hassan", 103, 20000, "UIT", 6);

    e1->displayInfo();
    e2->displayInfo();
    e3->displayInfo();

    delete e1;
    delete e2;
    delete e3;

    return 0;
}
