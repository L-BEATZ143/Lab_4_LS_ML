#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string foodName;
    std::string cashierNotes;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    char memberCheck;

    std::cout << std::setw(10) << std::left << "Enter food name: " << std::endl;
    std::getline(std::cin, foodName);

    std::cout << std::setw(10) << std::left << "Enter item code: " << std::endl;
    std::cin >> itemCode;

    std::cout << std::setw(10) << std::left << "Enter quantity: " << std::endl;
    std::cin >> itemQuantity;

    std::cout << std::setw(10) << std::left << "Enter unit price: " << std::endl;
    std::cin >> unitPrice;

    std::cout << std::setw(10) << std::left << "Are you a member? (y/n): " << std::endl;
    std::cin >> memberCheck;

    std::cin.ignore();
    std::cout << std::setw(10) << std::left << "Enter cashier notes: " << std::endl;
    std::getline(std::cin, cashierNotes);

    double totalCost = itemQuantity * unitPrice;

     if (memberCheck == 'y' || memberCheck == 'Y') {
        totalCost = totalCost * 0.90;
    }
     std::cout << "\n----- RECEIPT -----\n";
     std::cout << std::left << std::setw(15) << "item"
         << std::setw(10) << "Code"
         << std::setw(10) << "Qty"
         << std::setw(10) << "Price" << std::endl;
     std::cout << std::left << std::setw(15) << foodName
         << std::setw(10) << itemCode
         << std::setw(10) << itemQuantity
         << std::fixed << std::setprecision(2) << unitPrice << std::endl;

     std::cout << "Total: $" << std::fixed << std::setprecision(2) << totalCost << std::endl;

     std::cout << "\n----- INVENTORY AUDIT -----\n";

     std::cout << std::left
         << std::setw(15) << "Item"
         << std::setw(10) << "Code"
         << std::right << std::setw(10) << "Quantity" << std::endl;

     std::cout << std::left
         << std::setw(15) << foodName
         << std::setw(10) << itemCode
         << std::right << std::setw(10) << itemQuantity << std::endl;
}