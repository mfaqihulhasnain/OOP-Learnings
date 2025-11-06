#include "Restaurant.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <limits>

Restaurant::Restaurant() {
    loadData();
}

Restaurant::~Restaurant() {
    saveData();
}

void Restaurant::addMenuItem(const MenuItem& item) {
    menu.push_back(item);
}

void Restaurant::showMenu() const {
    std::cout << "\n===== MENU =====\n";
    std::cout << std::setw(5) << "ID" << std::setw(20) << "Name" 
              << std::setw(10) << "Price" << std::endl;
    std::cout << std::string(35, '-') << std::endl;
    
    for (const auto& item : menu) {
        std::cout << std::setw(5) << item.getId()
                  << std::setw(20) << item.getName()
                  << std::setw(10) << std::fixed << std::setprecision(2) 
                  << item.getPrice() << std::endl;
    }
}

MenuItem* Restaurant::findMenuItem(int id) {
    for (auto& item : menu) {
        if (item.getId() == id) {
            return &item;
        }
    }
    return nullptr;
}

void Restaurant::takeOrder() {
    Order order(orders.size() + 1);
    char more;
    
    do {
        showMenu();
        int id, quantity;
        
        std::cout << "\nEnter item ID: ";
        std::cin >> id;
        
        MenuItem* item = findMenuItem(id);
        if (!item) {
            std::cout << "Invalid item ID!\n";
            continue;
        }
        
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        
        if (quantity <= 0) {
            std::cout << "Invalid quantity!\n";
            continue;
        }
        
        order.addItem(*item, quantity);
        
        std::cout << "Add more items? (y/n): ";
        std::cin >> more;
    } while (more == 'y' || more == 'Y');
    
    orders.push_back(order);
    displayBill(order);
}

void Restaurant::displayBill(const Order& order) const {
    const double TAX_RATE = 0.05;  // 5% tax
    
    std::cout << "\n===== BILL =====\n";
    std::cout << "Order ID: " << order.getOrderId() << std::endl;
    std::cout << "Date: " << order.timestampToString() << std::endl;
    std::cout << std::string(35, '-') << std::endl;
    
    std::cout << std::setw(20) << "Item"
              << std::setw(8) << "Qty"
              << std::setw(10) << "Price"
              << std::setw(12) << "Total" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    for (const auto& item : order.getItems()) {
        std::cout << std::setw(20) << item.item.getName()
                  << std::setw(8) << item.quantity
                  << std::setw(10) << std::fixed << std::setprecision(2) 
                  << item.item.getPrice()
                  << std::setw(12) << (item.quantity * item.item.getPrice()) 
                  << std::endl;
    }
    
    double subtotal = order.calculateTotal();
    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;
    
    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::setw(38) << "Subtotal:" 
              << std::setw(12) << subtotal << std::endl;
    std::cout << std::setw(38) << "Tax (5%):" 
              << std::setw(12) << tax << std::endl;
    std::cout << std::setw(38) << "Total:" 
              << std::setw(12) << total << std::endl;
}

double Restaurant::getTotalSales() const {
    double total = 0.0;
    for (const auto& order : orders) {
        total += order.calculateTotal(0.05);  // including 5% tax
    }
    return total;
}

void Restaurant::addEmployee(std::unique_ptr<Employee> emp) {
    employees.push_back(std::move(emp));
}

void Restaurant::showEmployees() const {
    std::cout << "\n===== EMPLOYEES =====\n";
    for (const auto& emp : employees) {
        emp->showDetails();
        std::cout << std::string(30, '-') << std::endl;
    }
}

void Restaurant::loadData() {
    // Load menu items
    try {
        std::vector<MenuItem> loadedMenu = MenuItem::loadFromFile(MENU_FILE);
        menu = std::move(loadedMenu);
    } catch (const std::exception& e) {
        std::cerr << "Error loading menu: " << e.what() << std::endl;
    }
    
    // TODO: Load orders and employees if needed
}

void Restaurant::saveData() const {
    // Save menu items
    try {
        if (!menu.empty()) {
            menu[0].saveToFile(MENU_FILE);  // First item's save method will handle the whole vector
        }
    } catch (const std::exception& e) {
        std::cerr << "Error saving menu: " << e.what() << std::endl;
    }
    
    // TODO: Save orders and employees if needed
}

void Restaurant::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Restaurant::pauseScreen() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}