#include "MenuItem.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>

MenuItem::MenuItem() : id(0), name(""), price(0.0) {}

MenuItem::MenuItem(int id, const std::string& name, double price)
    : id(id), name(name), price(price) {}

int MenuItem::getId() const { return id; }
void MenuItem::setId(int id) { this->id = id; }

std::string MenuItem::getName() const { return name; }
void MenuItem::setName(const std::string& name) { this->name = name; }

double MenuItem::getPrice() const { return price; }
void MenuItem::setPrice(double price) { this->price = price; }

// CSV operations
std::string MenuItem::toCSV() const {
    std::ostringstream oss;
    oss << id << "," << name << "," << price;
    return oss.str();
}

MenuItem MenuItem::fromCSV(const std::string& line) {
    std::istringstream iss(line);
    std::string token;
    std::vector<std::string> tokens;
    
    while (std::getline(iss, token, ',')) {
        tokens.push_back(token);
    }
    
    if (tokens.size() != 3) {
        throw std::runtime_error("Invalid CSV format for MenuItem");
    }
    
    try {
        int id = std::stoi(tokens[0]);
        std::string name = tokens[1];
        double price = std::stod(tokens[2]);
        return MenuItem(id, name, price);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error parsing MenuItem data: " + std::string(e.what()));
    }
}

std::vector<MenuItem> MenuItem::loadFromFile(const std::string& filename) {
    std::vector<MenuItem> items;
    std::ifstream file(filename);
    
    if (!file) {
        return items;  // Return empty vector if file doesn't exist
    }
    
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            try {
                items.push_back(fromCSV(line));
            } catch (const std::exception& e) {
                std::cerr << "Warning: Skipping invalid line: " << e.what() << std::endl;
            }
        }
    }
    
    return items;
}

void MenuItem::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        throw std::runtime_error("Unable to open file for writing: " + filename);
    }
    
    file << toCSV() << std::endl;
}
