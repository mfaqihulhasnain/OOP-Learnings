#pragma once
#include <string>
#include <iostream>

// Employee base class: demonstrates abstraction and polymorphism via virtual methods
class Employee {
protected:
    int id;
    std::string name;
    std::string role;

public:
    Employee();
    Employee(int id, const std::string &name, const std::string &role);
    virtual ~Employee();

    int getId() const;
    std::string getName() const;
    std::string getRole() const;

    void setName(const std::string &name);
    void setRole(const std::string &role);

    // virtual function for polymorphism
    virtual void showDetails() const;
};

// Derived classes (inheritance)
class Chef : public Employee {
public:
    Chef(int id, const std::string &name);
    void showDetails() const override;
};

class Waiter : public Employee {
public:
    Waiter(int id, const std::string &name);
    void showDetails() const override;
};

class Manager : public Employee {
public:
    Manager(int id, const std::string &name);
    void showDetails() const override;
};
