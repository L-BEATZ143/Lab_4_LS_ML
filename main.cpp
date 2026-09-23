#include <iostream>
#include <string>
#include <iomanip>
int main() {
    std::string foodName;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    bool memberCheck;
 
    std::cout << std::setw(10) << std::left << "Enter food name: ";
    std::getline(std::cin, foodName);

    std::cout << std::setw(10) << std::left << "Enter item code: ";
    std::cin >> std::setw(10) >> std::left >> itemCode;

    std::cout << std::setw(10) << std::left << "Enter quantity: ";
    std::cin >> std::setw(10) >> std::left >> itemQuantity;

    std::cout << std::setw(10) << std::left << std::setprecision(2) << "Enter unit price: ";
    std::cin >> std::setw(10) >> std::left >> unitPrice;

    std::cout << std::setw(10) << std::left << "Are you a member?: ";
    std::cin >> std::setw(10) >> std::left >> memberCheck;

//pushinput again
}