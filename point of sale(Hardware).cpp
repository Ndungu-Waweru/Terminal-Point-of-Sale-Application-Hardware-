#include <iostream>
#include <string>
#include <iomanip>

class HardwareItem {
private:
    std::string itemName;
    int quantity;
    double price;

public:
    HardwareItem(std::string name, int qty, double itemPrice)
        : itemName(name), quantity(qty), price(itemPrice) {}

    double getTotalCost() const {
        return quantity * price;
    }

    void display() const {
        std::cout << std::left << std::setw(20) << itemName
                  << std::right << std::setw(5) << quantity
                  << std::setw(10) << price
                  << std::setw(12) << getTotalCost() << std::endl;
    }
};

int main() {
    std::string itemName;
    int quantity;
    double price;
    char choice;

    std::cout << "========= Hardware Point of Sale =========" << std::endl;

    do {
        std::cout << "Enter item name: ";
        std::getline(std::cin, itemName);

        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        std::cout << "Enter price per item: $";
        std::cin >> price;

        std::cin.ignore(); // To consume the newline character

        HardwareItem item(itemName, quantity, price);

        std::cout << "\n=========== Receipt ===========" << std::endl;
        std::cout << std::left << std::setw(20) << "Item Name"
                  << std::right << std::setw(5) << "Qty"
                  << std::setw(10) << "Price"
                  << std::setw(12) << "Total Cost" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;

        item.display();

        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Total: $" << item.getTotalCost() << std::endl;

        std::cout << "\nDo you want to add another item? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(); // To consume the newline character

        std::cout << std::endl;
    } while (tolower(choice) == 'y');

    std::cout << "Thank you for shopping with us!" << std::endl;

    return 0;
}
