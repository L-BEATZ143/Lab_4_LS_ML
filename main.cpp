#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string foodName;
    std::string cashierNotes;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    bool memberCheck;

    std::cout << std::setw(10) << std::left << "Enter food name: " << std::endl;
    std::getline(std::cin, foodName);

    std::cout << std::setw(10) << std::left << "Enter item code: " << std::endl;
    std::cin >> itemCode;

    std::cout << std::setw(10) << std::left << "Enter quantity: " << std::endl;
    std::cin >> itemQuantity;

    std::cout << std::setw(10) << std::left << "Enter unit price: " << std::endl;
    std::cin >> unitPrice;

    std::cout << std::setw(10) << std::left << "Are you a member?: " << std::endl;
    std::cin >> memberCheck;

    std::cin.ignore();
    std::cout << std::setw(10) << std::left << "Enter cashier notes: " << std::endl;
    std::getline(std::cin, cashierNotes);


    if (memberCheck = true) { 
        auto totalCost = itemQuantity * unitPrice * 0.9;
    }
    else {
        auto totalCost = itemQuantity * unitPrice * 0.9;
    }
}