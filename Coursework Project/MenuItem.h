#pragma once
#include <string>
#include <vector>

// MenuItem class: demonstrates encapsulation (private members + public getters/setters)
class MenuItem {
private:
    int id;
    std::string name;
    double price;

public:
    MenuItem();
    MenuItem(int id, const std::string& name, double price);

    // getters/setters (encapsulation)
    int getId() const;
    void setId(int id);

    std::string getName() const;
    void setName(const std::string& name);

    double getPrice() const;
    void setPrice(double price);

    // File operations
    std::string toCSV() const;
    static MenuItem fromCSV(const std::string& line);
    static std::vector<MenuItem> loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};
