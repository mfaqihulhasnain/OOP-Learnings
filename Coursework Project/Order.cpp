#include "Order.h"
#include <sstream>
#include <iomanip>

Order::Order() : orderId(0), timestamp(std::time(nullptr)) {}
Order::Order(int id) : orderId(id), timestamp(std::time(nullptr)) {}

int Order::getOrderId() const { return orderId; }

void Order::addItem(const MenuItem &item, int quantity) {
    if (quantity <= 0) return;
    items.push_back({item, quantity});
}

double Order::calculateTotal(double taxRate, double discount) const {
    double subtotal = 0.0;
    for (const auto &oi : items) {
        subtotal += oi.item.getPrice() * oi.quantity;
    }
    double disc = subtotal * discount;
    double taxed = (subtotal - disc) * (1.0 + taxRate);
    return taxed;
}

const std::vector<OrderItem>& Order::getItems() const { return items; }
std::time_t Order::getTimestamp() const { return timestamp; }

std::string Order::timestampToString() const {
    std::tm *tm = std::localtime(&timestamp);
    std::ostringstream oss;
    oss << std::put_time(tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
