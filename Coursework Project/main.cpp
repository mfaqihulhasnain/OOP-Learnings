#include <iostream>
#include <limits>
#include <memory>
#include <iomanip>
#include "Restaurant.h"

// Function to display main menu
void showMainMenu() {
    std::cout << "\n===== RESTAURANT MANAGEMENT SYSTEM =====\n"
              << "1. Add Menu Item\n"
              << "2. Show Menu\n"
              << "3. Take Order\n"
              << "4. Show Total Sales\n"
              << "5. Manage Employees\n"
              << "6. Exit\n"
              << "Choice: ";
}

// Function to handle employee management submenu
void handleEmployeeMenu(Restaurant& restaurant) {
    while (true) {
        std::cout << "\n===== EMPLOYEE MANAGEMENT =====\n"
                  << "1. Add Employee\n"
                  << "2. Show All Employees\n"
                  << "3. Back to Main Menu\n"
                  << "Choice: ";
        
        int choice;
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                std::cout << "\nSelect employee type:\n"
                          << "1. Chef\n"
                          << "2. Waiter\n"
                          << "3. Manager\n"
                          << "Choice: ";
                
                int type;
                std::cin >> type;
                
                std::cout << "Enter employee ID: ";
                int id;
                std::cin >> id;
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << "Enter employee name: ";
                std::string name;
                std::getline(std::cin, name);
                
                std::unique_ptr<Employee> emp;
                switch (type) {
                    case 1:
                        emp = std::make_unique<Chef>(id, name);
                        break;
                    case 2:
                        emp = std::make_unique<Waiter>(id, name);
                        break;
                    case 3:
                        emp = std::make_unique<Manager>(id, name);
                        break;
                    default:
                        std::cout << "Invalid employee type!\n";
                        continue;
                }
                
                restaurant.addEmployee(std::move(emp));
                std::cout << "Employee added successfully!\n";
                break;
            }
            case 2:
                restaurant.showEmployees();
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice!\n";
        }
    }
}

int main() {
    Restaurant restaurant;
    
    while (true) {
        Restaurant::clearScreen();
        showMainMenu();
        
        int choice;
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                std::cout << "\n===== ADD MENU ITEM =====\n";
                
                std::cout << "Enter item ID: ";
                int id;
                std::cin >> id;
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << "Enter item name: ";
                std::string name;
                std::getline(std::cin, name);
                
                std::cout << "Enter price: ";
                double price;
                std::cin >> price;
                
                restaurant.addMenuItem(MenuItem(id, name, price));
                std::cout << "Menu item added successfully!\n";
                break;
            }
            case 2:
                restaurant.showMenu();
                break;
            case 3:
                restaurant.takeOrder();
                break;
            case 4: {
                double totalSales = restaurant.getTotalSales();
                std::cout << "\nTotal Sales: $" << std::fixed 
                          << std::setprecision(2) << totalSales << std::endl;
                break;
            }
            case 5:
                handleEmployeeMenu(restaurant);
                break;
            case 6:
                std::cout << "\nSaving data and exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice!\n";
        }
        
        Restaurant::pauseScreen();
    }
    
    return 0;
}