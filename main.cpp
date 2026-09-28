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
    
    cout << setw(15) << left << "Items"
        << setw(15) << "Small (S)"
        << setw(15) << "Medium (M)"
        << setw(15) << "Large (L)" << endl;

    cout << setw(15) << left << "Slushie"
        << setw(15) << "3.50"
        << setw(15) << "4.50"
        << setw(15) << "5.50" << endl;

    cout << setw(15) << left << "Vinyl Combo"
        << setw(15) << "20.29"
        << setw(15) << "20.79"
        << setw(15) << "21.29" << endl;

    cout << setw(15) << left << "Vinyl Combo"
        << setw(15) << "20.29"
        << setw(15) << "20.79"
        << setw(15) << "21.29" << endl;

    cout << setw(15) << left << "Churro"
        << setw(15) << "1.99"
        << setw(15) << "2.99"
        << setw(15) << "3.99" << endl;

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
         << right << setw(10) << "Quantity" << endl;

     cout << left
         << setw(15) << foodName
         << setw(10) << itemCode
         << right << setw(10) << itemQuantity << endl;
}