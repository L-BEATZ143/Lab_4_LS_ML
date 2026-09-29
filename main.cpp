#include <iostream>
#include <string>
#include <iomanip>

int main() {
    using namespace std;
    string foodName;
    string cashierNotes;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    char memberCheck;
    char size;
    cout << setw(15) << left << "Items"
        << setw(15) << "Small (S)"
        << setw(15) << "Medium (M)"
        << setw(15) << "Large (L)" << endl;

    cout << setw(15) << left << "A. Slushie"
        << setw(15) << "3.50"
        << setw(15) << "4.50"
        << setw(15) << "5.50" << endl;

    cout << setw(15) << left << "B. Burger"
        << setw(15) << "2.99"
        << setw(15) << "4.99"
        << setw(15) << "6.99" << endl;

    cout << setw(15) << left << "C. Vinyl Combo"
        << setw(15) << "19.99"
        << setw(15) << "20.99"
        << setw(15) << "21.99" << endl;

    cout << setw(15) << left << "D. Churro"
        << setw(15) << "1.99"
        << setw(15) << "2.99"
        << setw(15) << "3.99" << endl;

    cout << "enter item code" << endl;
    cin >> itemCode;
    cout << "enter size" << endl;
    cin >> size;
    if (itemCode == 'a' || itemCode == 'A'){
        if (size == 's' || size == 'S'){
            unitPrice = 3.50;
        }
        else if (size == 'm' || size == 'M'){
            unitPrice = 4.50;
        }
        else if (size == 'l' || size == 'L'){
            unitPrice = 5.50;
        }
    
    }
    else if (itemCode == 'b' || itemCode == 'B'){
        if (size == 's' || size == 'S'){
            unitPrice = 2.99;
        }
        else if (size == 'm' || size == 'M'){
            unitPrice = 4.99;
        }
        else if (size == 'l' || size == 'L'){
            unitPrice = 6.99;
        }

    }
    else if (itemCode == 'c' || itemCode == 'C'){
        if (size == 's' || size == 'S'){
            unitPrice = 19.99;
        }
        else if (size == 'm' || size == 'M'){
            unitPrice = 20.99;
        }
        else if (size == 'l' || size == 'L'){
            unitPrice = 21.99;
        }

    }
    else if (itemCode == 'd' || itemCode == 'D'){
        if (size == 's' || size == 'S'){
            unitPrice = 1.99;
        }
        else if (size == 'm' || size == 'M'){
            unitPrice = 2.99;
        }
        else if (size == 'l' || size == 'L'){
            unitPrice = 3.99;
        }

    }
    cout << setw(10) << left << "Enter quantity: " << endl;
    cin >> itemQuantity;

    cout << setw(10) << left << "Are you a member? (y/n): " << endl;
    cin >> memberCheck;

    cin.ignore();
    cout << setw(10) << left << "Enter cashier notes: " << endl;
    getline(cin, cashierNotes);

    double totalCost = itemQuantity * unitPrice;

     if (memberCheck == 'y' || memberCheck == 'Y') {
        totalCost = totalCost * 0.90;
    }
     cout << "\n----- RECEIPT -----\n";
     cout << left << setw(15) << "item"
         << setw(10) << "Code"
         << setw(10) << "Qty"
         << setw(10) << "Price" << endl;
     cout << left << setw(15) << foodName
         << setw(10) << itemCode
         << setw(10) << itemQuantity
         << fixed << setprecision(2) << unitPrice << endl;

     cout << "Total: $" << fixed << setprecision(2) << totalCost << endl;

     cout << "\n----- INVENTORY AUDIT -----\n";

     cout << left
         << setw(15) << "Item"
         << setw(10) << "Code"
         << right << setw(10) << "Qty" << endl;

     cout << left
         << setw(15) << foodName
         << setw(10) << itemCode
         << right << setw(10) << itemQuantity << endl;

    
}