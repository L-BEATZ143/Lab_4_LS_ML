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
    double stateTax;
    double countyTax;
    double municipalTax;
    char tips;
    double tipNum;
    string tipPercent;
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
    cout << "enter size (s/m/l)" << endl;
    cin >> size;
    if (itemCode == 'a' || itemCode == 'A'){
        foodName = "Slushie";
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
        foodName = "Burger";
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
        foodName = "Vinyl Combo";
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
        foodName = "Churro";
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
    cout << "How much do you want to tip" << endl;
    cout << "A. 15% = $1.50" << endl;
    cout << "B. 20% = $2.00" << endl;
    cout << "C. 25% = $2.50" << endl;
    cout << "D. Other E. No Tip" << endl;
    cin >> tips;
    if (tips == 'a' || tips == 'A'){
        tipNum = 1.00;
        tipPercent = "15%";
    }

    else if (tips == 'b' || tips == 'B'){
        tipNum = 2.00;
        tipPercent = "20%";
    }

    else if (tips == 'c' || tips == 'C'){
        tipNum = 2.50;
        tipPercent = "25%";
    }

    else if (tips == 'd' || tips == 'D'){
        cout << "how much would you actually want to tip:" << endl;
        cin >> tipNum;
        tipPercent = "Custom tip";
    }
    else if (tips == 'e' || tips == 'E'){
        tipNum = 0;
        tipPercent = "N/A";
    }
    double totalCost = itemQuantity * unitPrice;

     if (memberCheck == 'y' || memberCheck == 'Y')
     {
        totalCost = totalCost * 0.90;
    
     }
     cout << "\n----- RECEIPT -----\n";
     cout << left << setw(15) << "Item"
         << setw(10) << "Code"
         << setw(10) << "Size"
         << setw(10) << "Qty"
         << setw(10) << "Price" << endl;
     cout << left << setw(15) << foodName
         << setw(10) << itemCode
         << setw(10) << size
         << setw(10) << itemQuantity
         << fixed << setprecision(2) << unitPrice << endl;

     cout << "Total: $" << fixed << setprecision(2) << totalCost << endl;

     cout << "\n----- INVENTORY AUDIT -----\n";

     cout << left
         << setw(15) << "Item"
         << setw(10) << "Code"
         << setw(10) << "Size"
         << right << setw(10) << "Qty" << endl;

     cout << left
         << setw(15) << foodName
         << setw(10) << itemCode
         << setw(10) << size
         << right << setw(10) << itemQuantity << endl;

     stateTax = totalCost * 0.065;
     countyTax = totalCost * 0.005;
     municipalTax = totalCost * 0.02125;
     totalCost = (totalCost + stateTax + countyTax + municipalTax + tipNum);
     cout << "\n----- TAXES -----\n";

     cout << left
         << setw(25) << "Tax"
         << setw(15) << "Percentage"
         << setw(10) << "Cost" << endl
         << setw(25) << "Arkansas State Tax:"
         << setw(15) << "6.5%"
         << setw(10) << setprecision(2) << stateTax << endl
         << setw(25) << "Faulkner County Tax:"
         << setw(15) << "0.5%"
         << setw(10) << setprecision(2) << countyTax << endl
         << setw(25) << "Conway Municipal Tax:"
         << setw(15) << "0.02125%"
         << setw(10) << setprecision(2) << municipalTax << endl
         << setw(25) << "TIP"
         << setw(15) << tipPercent
         << setw(10) << setprecision(2) << totalCost << endl;
cout << "total: " << totalCost;
}