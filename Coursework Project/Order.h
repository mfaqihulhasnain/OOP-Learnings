#pragma once
#include "MenuItem.h"
#include <vector>
#include <string>
#include <ctime>

// OrderItem pairs a MenuItem with a quantity
struct OrderItem {
    MenuItem item;
    int quantity;
};

// Order class: stores ordered items, timestamp, and calculation methods
class Order {
private:
    int orderId;
    std::vector<OrderItem> items;
    std::time_t timestamp;

public:
    Order();
    Order(int id);

    int getOrderId() const;
    void addItem(const MenuItem &item, int quantity);
    double calculateTotal(double taxRate = 0.0, double discount = 0.0) const; // taxRate and discount are fractions (e.g., 0.05)
    const std::vector<OrderItem>& getItems() const;
    std::time_t getTimestamp() const;

    // Helpers to format/save order as CSV later
    std::string timestampToString() const;
};
