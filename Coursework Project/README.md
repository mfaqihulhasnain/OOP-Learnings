# Restaurant Management System

A C++ console application demonstrating Object-Oriented Programming principles.

## Features

- Menu item management
- Order processing with tax calculation
- Employee management (Chef, Waiter, Manager)
- Sales tracking
- File persistence (CSV format)

## OOP Concepts Demonstrated

1. **Encapsulation**
   - Private data members with public getters/setters
   - Data hiding in all classes

2. **Inheritance**
   - Employee base class
   - Derived classes: Chef, Waiter, Manager

3. **Polymorphism**
   - Virtual functions (showDetails)
   - Runtime polymorphism with Employee hierarchy

4. **Abstraction**
   - Clear class interfaces
   - Complex operations hidden behind simple methods

## Build Instructions (Windows)

1. Open Command Prompt in the project directory
2. Compile the project:
```cmd
g++ -o restaurant.exe main.cpp MenuItem.cpp Order.cpp Employee.cpp Restaurant.cpp
```
3. Run the program:
```cmd
restaurant.exe
```

## Usage

The program provides a menu-driven interface:
1. Add Menu Item - Create new menu items
2. Show Menu - Display all menu items
3. Take Order - Process a new customer order
4. Show Total Sales - View daily sales total
5. Manage Employees - Add/view employee information
6. Exit - Save and quit

## Data Persistence

The program uses CSV files to store data:
- menu.csv - Menu items
- orders.csv - Order history
- employees.csv - Employee records

Files are automatically loaded on startup and saved on exit.