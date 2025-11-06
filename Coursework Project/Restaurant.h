#pragma once
#include <vector>
#include <memory>
#include "MenuItem.h"
#include "Order.h"
#include "Employee.h"

class Restaurant {
private:
    std::vector<MenuItem> menu;
    std::vector<Order> orders;
    std::vector<std::unique_ptr<Employee>> employees;
    
    // File paths for persistence
    const std::string MENU_FILE = "menu.csv";
    const std::string ORDERS_FILE = "orders.csv";
    const std::string EMPLOYEES_FILE = "employees.csv";

public:
    Restaurant();
    ~Restaurant();

    // Menu operations
    void addMenuItem(const MenuItem& item);
    void showMenu() const;
    MenuItem* findMenuItem(int id);
    
    // Order operations
    void takeOrder();
    void showOrder(const Order& order) const;
    double getTotalSales() const;
    
    // Employee operations
    void addEmployee(std::unique_ptr<Employee> emp);
    void showEmployees() const;
    
    // File operations
    void loadData();
    void saveData() const;
    
    // Helper methods
    void displayBill(const Order& order) const;
    static void clearScreen();
    static void pauseScreen();
};