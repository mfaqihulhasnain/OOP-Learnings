#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

const int MAX_MENU_ITEMS = 100;
const int MAX_ORDERS = 500;
const int MAX_ORDER_ITEMS = 50;
const int MAX_EMPLOYEES = 50;

// ==================== MenuItem Class ====================
class MenuItem
{
private:
    int id;
    string name;
    double price;

public:
    MenuItem() : id(0), name(""), price(0.0) {}
    MenuItem(int id, const string &name, double price)
        : id(id), name(name), price(price) {}

    // getters/setters (encapsulation)
    int getId() const { return id; }
    void setId(int id) { this->id = id; }

    string getName() const { return name; }
    void setName(const string &name) { this->name = name; }

    double getPrice() const { return price; }
    void setPrice(double price) { this->price = price; }

    // CSV operations
    string toCSV() const
    {
        ostringstream oss;
        oss << id << "," << name << "," << price;
        return oss.str();
    }

    static MenuItem fromCSV(const string &line)
    {
        istringstream iss(line);
        string token;
        string tokens[3];
        int tokenCount = 0;

        while (getline(iss, token, ',') && tokenCount < 3)
        {
            tokens[tokenCount++] = token;
        }

        if (tokenCount != 3)
        {
            throw runtime_error("Invalid CSV format for MenuItem");
        }

        try
        {       
            int id = stoi(tokens[0]);
            string name = tokens[1];
            double price = stod(tokens[2]);
            return MenuItem(id, name, price);
        }
        catch (const exception &e)
        {
            throw runtime_error("Error parsing MenuItem data: " + string(e.what()));
        }
    }

    static int loadFromFile(const string &filename, MenuItem items[], int maxSize)
    {
        ifstream file(filename);
        int count = 0;

        if (!file)
        {
            return 0; // Return 0 if file doesn't exist
        }

        string line;
        while (getline(file, line) && count < maxSize)
        {
            if (!line.empty())
            {
                try
                {
                    items[count++] = fromCSV(line);
                }
                catch (const exception &e)
                {
                    cerr << "Warning: Skipping invalid line: " << e.what() << endl;
                }
            }
        }

        return count;
    }

    void saveToFile(const string &filename) const
    {
        ofstream file(filename, ios::app);
        if (!file)
        {
            throw runtime_error("Unable to open file for writing: " + filename);
        }

        file << toCSV() << endl;
    }
};

// ==================== Order Classes ====================
// OrderItem pairs a MenuItem with a quantity
struct OrderItem
{
    MenuItem item;
    int quantity;
};

// Order class: stores ordered items, timestamp, and calculation methods
class Order
{
private:
    int orderId;
    OrderItem items[MAX_ORDER_ITEMS];
    int itemCount;
    time_t timestamp;

public:
    Order() : orderId(0), itemCount(0), timestamp(time(nullptr)) {}
    Order(int id) : orderId(id), itemCount(0), timestamp(time(nullptr)) {}

    int getOrderId() const { return orderId; }
    int getItemCount() const { return itemCount; }

    void addItem(const MenuItem &item, int quantity)
    {
        if (quantity <= 0 || itemCount >= MAX_ORDER_ITEMS)
            return;
        items[itemCount].item = item;
        items[itemCount].quantity = quantity;
        itemCount++;
    }

    double calculateTotal(double taxRate = 0.0, double discount = 0.0) const
    {
        double subtotal = 0.0;
        for (int i = 0; i < itemCount; i++)
        {
            subtotal += items[i].item.getPrice() * items[i].quantity;
        }
        double disc = subtotal * discount;
        double taxed = (subtotal - disc) * (1.0 + taxRate);
        return taxed;
    }

    const OrderItem *getItems() const { return items; }
    time_t getTimestamp() const { return timestamp; }

    string timestampToString() const
    {
        tm *tm = localtime(&timestamp);
        ostringstream oss;
        oss << put_time(tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
};

// ==================== Employee Classes ====================
// Employee base class: demonstrates abstraction and polymorphism via virtual methods
class Employee
{
protected:
    int id;
    string name;
    string role;

public:
    Employee() : id(0), name(""), role("") {}
    Employee(int id, const string &name, const string &role)
        : id(id), name(name), role(role) {}
    virtual ~Employee() {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getRole() const { return role; }

    void setName(const string &name) { this->name = name; }
    void setRole(const string &role) { this->role = role; }

    // virtual function for polymorphism
    virtual void showDetails() const
    {
        cout << "ID: " << id << endl
                  << "Name: " << name << endl
                  << "Role: " << role << endl;
    }
};

// Derived classes (inheritance)
class Chef : public Employee
{
public:
    Chef(int id, const string &name)
        : Employee(id, name, "Chef") {}

    void showDetails() const override
    {
        Employee::showDetails();
        cout << "Specialization: Kitchen Operations" << endl;
    }
};

class Waiter : public Employee
{
public:
    Waiter(int id, const string &name)
        : Employee(id, name, "Waiter") {}

    void showDetails() const override
    {
        Employee::showDetails();
        cout << "Specialization: Customer Service" << endl;
    }
};

class Manager : public Employee
{
public:
    Manager(int id, const string &name)
        : Employee(id, name, "Manager") {}

    void showDetails() const override
    {
        Employee::showDetails();
        cout << "Specialization: Restaurant Management" << endl;
    }
};

// ==================== Restaurant Class ====================
class Restaurant
{
private:
    MenuItem menu[MAX_MENU_ITEMS];
    int menuCount;

    Order orders[MAX_ORDERS];
    int orderCount;

    Employee *employees[MAX_EMPLOYEES];
    int employeeCount;

    // File paths for persistence
    const string MENU_FILE = "menu.csv";
    const string ORDERS_FILE = "orders.csv";
    const string EMPLOYEES_FILE = "employees.csv";

public:
    Restaurant() : menuCount(0), orderCount(0), employeeCount(0)
    {
        // Initialize employee pointers to nullptr
        for (int i = 0; i < MAX_EMPLOYEES; i++)
        {
            employees[i] = nullptr;
        }
        loadData();
    }

    ~Restaurant()
    {
        saveData();
        // Clean up dynamically allocated employees
        for (int i = 0; i < employeeCount; i++)
        {
            delete employees[i];
        }
    }

    // Menu operations
    void addMenuItem(const MenuItem &item)
    {
        if (menuCount < MAX_MENU_ITEMS)
        {
            menu[menuCount++] = item;
        }
        else
        {
            cout << "Menu is full! Cannot add more items.\n";
        }
    }

    void showMenu() const
    {
        cout << "\n===== MENU =====\n";
        cout << setw(5) << "ID" << setw(20) << "Name"
                  << setw(10) << "Price" << endl;
        cout << string(35, '-') << endl;

        for (int i = 0; i < menuCount; i++)
        {
            cout << setw(5) << menu[i].getId()
                      << setw(20) << menu[i].getName()
                      << setw(10) << fixed << setprecision(2)
                      << menu[i].getPrice() << endl;
        }
    }

    MenuItem *findMenuItem(int id)
    {
        for (int i = 0; i < menuCount; i++)
        {
            if (menu[i].getId() == id)
            {
                return &menu[i];
            }
        }
        return nullptr;
    }

    // Order operations
    void takeOrder()
    {
        if (orderCount >= MAX_ORDERS)
        {
            cout << "Order limit reached! Cannot take more orders.\n";
            return;
        }

        Order order(orderCount + 1);
        char more;

        do
        {
            showMenu();
            int id, quantity;

            cout << "\nEnter item ID: ";
            cin >> id;

            MenuItem *item = findMenuItem(id);
            if (!item)
            {
                cout << "Invalid item ID!\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity <= 0)
            {
                cout << "Invalid quantity!\n";
                continue;
            }

            order.addItem(*item, quantity);

            cout << "Add more items? (y/n): ";
            cin >> more;
        } while (more == 'y' || more == 'Y');

        orders[orderCount++] = order;
        displayBill(order);
    }

    void displayBill(const Order &order) const
    {
        const double TAX_RATE = 0.05; // 5% tax

        cout << "\n===== BILL =====\n";
        cout << "Order ID: " << order.getOrderId() << endl;
        cout << "Date: " << order.timestampToString() << endl;
        cout << string(35, '-') << endl;

        cout << setw(20) << "Item"
                  << setw(8) << "Qty"
                  << setw(10) << "Price"
                  << setw(12) << "Total" << endl;
        cout << string(50, '-') << endl;

        const OrderItem *items = order.getItems();
        for (int i = 0; i < order.getItemCount(); i++)
        {
            cout << setw(20) << items[i].item.getName()
                      << setw(8) << items[i].quantity
                      << setw(10) << fixed << setprecision(2)
                      << items[i].item.getPrice()
                      << setw(12) << (items[i].quantity * items[i].item.getPrice())
                      << endl;
        }

        double subtotal = order.calculateTotal();
        double tax = subtotal * TAX_RATE;
        double total = subtotal + tax;

        cout << string(50, '-') << endl;
        cout << setw(38) << "Subtotal:"
                  << setw(12) << subtotal << endl;
        cout << setw(38) << "Tax (5%):"
                  << setw(12) << tax << endl;
        cout << setw(38) << "Total:"
                  << setw(12) << total << endl;
    }

    double getTotalSales() const
    {
        double total = 0.0;
        for (int i = 0; i < orderCount; i++)
        {
            total += orders[i].calculateTotal(0.05); // including 5% tax
        }
        return total;
    }

    // Employee operations
    void addEmployee(Employee *emp)
    {
        if (employeeCount < MAX_EMPLOYEES)
        {
            employees[employeeCount++] = emp;
        }
        else
        {
            cout << "Employee limit reached! Cannot add more employees.\n";
            delete emp; // Clean up if we can't add
        }
    }

    void showEmployees() const
    {
        cout << "\n===== EMPLOYEES =====\n";
        for (int i = 0; i < employeeCount; i++)
        {
            employees[i]->showDetails();
            cout << string(30, '-') << endl;
        }
    }

    // File operations
    void loadData()
    {
        // Load menu items
        try
        {
            menuCount = MenuItem::loadFromFile(MENU_FILE, menu, MAX_MENU_ITEMS);
        }
        catch (const exception &e)
        {
            cerr << "Error loading menu: " << e.what() << endl;
        }

        // TODO: Load orders and employees if needed
    }

    void saveData() const
    {
        // Save menu items
        try
        {
            // Clear file first
            ofstream clearFile(MENU_FILE, ios::trunc);
            clearFile.close();

            // Save all items
            for (int i = 0; i < menuCount; i++)
            {
                menu[i].saveToFile(MENU_FILE);
            }
        }
        catch (const exception &e)
        {
            cerr << "Error saving menu: " << e.what() << endl;
        }

        // TODO: Save orders and employees if needed
    }

    // Helper methods
    static void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    static void pauseScreen()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
};

// ==================== Main Program Functions ====================
// Function to display main menu
void showMainMenu()
{
    cout << "\n===== RESTAURANT MANAGEMENT SYSTEM =====\n"
              << "1. Add Menu Item\n"
              << "2. Show Menu\n"
              << "3. Take Order\n"
              << "4. Show Total Sales\n"
              << "5. Manage Employees\n"
              << "6. Exit\n"
              << "Choice: ";
}

// Function to handle employee management submenu
void handleEmployeeMenu(Restaurant &restaurant)
{
    while (true)
    {
        cout << "\n===== EMPLOYEE MANAGEMENT =====\n"
                  << "1. Add Employee\n"
                  << "2. Show All Employees\n"
                  << "3. Back to Main Menu\n"
                  << "Choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\nSelect employee type:\n"
                      << "1. Chef\n"
                      << "2. Waiter\n"
                      << "3. Manager\n"
                      << "Choice: ";

            int type;
            cin >> type;

            cout << "Enter employee ID: ";
            int id;
            cin >> id;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter employee name: ";
            string name;
            getline(cin, name);

            Employee *emp = nullptr;
            switch (type)
            {
            case 1:
                emp = new Chef(id, name);
                break;
            case 2:
                emp = new Waiter(id, name);
                break;
            case 3:
                emp = new Manager(id, name);
                break;
            default:
                cout << "Invalid employee type!\n";
                continue;
            }

            restaurant.addEmployee(emp);
            cout << "Employee added successfully!\n";
            break;
        }
        case 2:
            restaurant.showEmployees();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

int main()
{
    Restaurant restaurant;
    
    while (true)
    {
        Restaurant::clearScreen();
        showMainMenu();
        
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n===== ADD MENU ITEM =====\n";

            cout << "Enter item ID: ";
            int id;
            cin >> id;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter item name: ";
            string name;
            getline(cin, name);

            cout << "Enter price: ";
            double price;
            cin >> price;

            restaurant.addMenuItem(MenuItem(id, name, price));
            cout << "Menu item added successfully!\n";
            break;
        }
        case 2:
            restaurant.showMenu();
            break;
        case 3:
            restaurant.takeOrder();
            break;
        case 4:
        {
            double totalSales = restaurant.getTotalSales();
            cout << "\nTotal Sales: $" << fixed
                      << setprecision(2) << totalSales << endl;
            break;
        }
        case 5:
            handleEmployeeMenu(restaurant);
            break;
        case 6:
            cout << "\nSaving data and exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
        
        Restaurant::pauseScreen();
    }
    
    return 0;
}
