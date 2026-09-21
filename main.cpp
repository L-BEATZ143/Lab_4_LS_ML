#include "receipt/receipt.hpp"

#include <iostream>

int main() {
    receipt::Receipt receipt("Example Market", "R-1001", 825);

    receipt.addItem({"Coffee", 2, 499});
    receipt.addItem({"Sandwich", 1, 899});
    receipt.addItem({"Reusable bag", 1, 25});

    std::cout << receipt.format();
    return 0;
}