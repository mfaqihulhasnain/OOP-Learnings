#include "Employee.h"
#include <iomanip>

// Base Employee class implementation
Employee::Employee() : id(0), name(""), role("") {}

Employee::Employee(int id, const std::string& name, const std::string& role)
    : id(id), name(name), role(role) {}

Employee::~Employee() {}

int Employee::getId() const { return id; }
std::string Employee::getName() const { return name; }
std::string Employee::getRole() const { return role; }

void Employee::setName(const std::string& name) { this->name = name; }
void Employee::setRole(const std::string& role) { this->role = role; }

void Employee::showDetails() const {
    std::cout << "ID: " << id << std::endl
              << "Name: " << name << std::endl
              << "Role: " << role << std::endl;
}

// Chef class implementation
Chef::Chef(int id, const std::string& name)
    : Employee(id, name, "Chef") {}

void Chef::showDetails() const {
    Employee::showDetails();
    std::cout << "Specialization: Kitchen Operations" << std::endl;
}

// Waiter class implementation
Waiter::Waiter(int id, const std::string& name)
    : Employee(id, name, "Waiter") {}

void Waiter::showDetails() const {
    Employee::showDetails();
    std::cout << "Specialization: Customer Service" << std::endl;
}

// Manager class implementation
Manager::Manager(int id, const std::string& name)
    : Employee(id, name, "Manager") {}

void Manager::showDetails() const {
    Employee::showDetails();
    std::cout << "Specialization: Restaurant Management" << std::endl;
}