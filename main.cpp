#include <iostream>
#include <string>
#include <iomanip>
int main() {
    std::string foodName;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    char memberAnswer; // 'y' or 'n'
    
    std::cout << "Enter food name: " << std::endl;
    getline(std::cin, foodName);
    std::cout << "Enter quantity: " << std::endl;
    std::cin >> itemQuantity;
    std::cout << "enter item code " << std::endl;
    std::cin >> itemCode;
    std::cout << "enter price: " << std::endl;
    std::cin >> unitPrice;
    std::cout << "are you a member? (y/n): " << std::endl;
    std::cin >> memberAnswer;

//typofix

}