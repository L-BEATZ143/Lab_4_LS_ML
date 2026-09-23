#include <iostream>
#include <string>
#include <iomanip>
int main() {
    std::string foodName;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    bool memberCheck;
    
    std::cout << "Enter food name: ";
    std::getline(std::cin, foodName);

    std::cout << "Enter item code: ";
    std::cin >> itemCode;

    std::cout << "Enter quantity: ";
    std::cin >> itemQuantity;

    std::cout << "Enter unit price: ";
    std::cin >> unitPrice;

    std::cout << "Are you a member?: ";
    std::cin >> memberCheck;

//pushinput again

}