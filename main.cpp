#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <fstream>
double setUnitPrice();
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
    double tipCost;
    string tipPercent;
    string customerName;
    ostringstream reciept;
    ostringstream audit;
    double totalCost = 0;
    int loyalty;
    double grandTotal = 0;
    int totalCustomers = 0;
    bool anotherCustomer;
    char cashierResponse;
    double food1Stock = 0;
    double food2Stock = 0;
    double food3Stock = 0;
    double food4Stock = 0;
    anotherCustomer = true;
    
    ifstream inputFile ("menu_text.txt");
    string food1, food2, food3, food4;
    double food1s, food1m, food1l, food2s, food2m, food2l, food3s, food3m, food3l, food4s, food4m, food4l;
    getline(inputFile, food1);
    inputFile >> food1s >> food1m >> food1l;
    inputFile.ignore();
    getline(inputFile, food2);
    inputFile >> food2s >> food2m >> food2l;
    inputFile.ignore();
    getline(inputFile, food3);
    inputFile >> food3s >> food3m >> food3l;
    inputFile.ignore();
    getline(inputFile, food4);
    inputFile >> food4s >> food4m >> food4l;
    inputFile.ignore();
    while (anotherCustomer) {
        loyalty = 0;
        cout << setw(15) << left << "Items"
            << setw(15) << "Small (S)"
            << setw(15) << "Medium (M)"
            << setw(15) << "Large (L)" << endl;

        cout << setw(15) << left << ("A. " + food1)
            << setw(15) << food1s
            << setw(15) << food1m
            << setw(15) << food1l << endl;

        cout << setw(15) << left << ("B. " + food2)
            << setw(15) << food2s
            << setw(15) << food2m
            << setw(15) << food2l << endl;

        cout << setw(15) << left << ("C. " + food3)
            << setw(15) << food3s
            << setw(15) << food3m
            << setw(15) << food3l << endl;

        cout << setw(15) << left << ("D. " + food4)
            << setw(15) << food4s
            << setw(15) << food4m
            << setw(15) << food4l << endl;
        cout << "E. Checkout" << endl;
        do {


            cout << "enter item code" << endl;
            cin >> itemCode;
            if (itemCode != 'e' && itemCode != 'E') {
                cout << "enter size (s/m/l)" << endl;
                cin >> size;
            }
            if (itemCode == 'e' || itemCode == 'E') {
                break;
            }
            else if (itemCode == 'a' || itemCode == 'A') {
                foodName = food1;
                if (size == 's' || size == 'S') {
                    
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food1Stock -= itemQuantity;
                }
                else if (size == 'm' || size == 'M') {
                    unitPrice = food1m;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food1Stock -= itemQuantity;
                }
                else if (size == 'l' || size == 'L') {
                    unitPrice = food1l;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food1Stock -= itemQuantity;
                }
            }
            else if (itemCode == 'b' || itemCode == 'B') {
                foodName = food2;
                if (size == 's' || size == 'S') {
                    unitPrice = food2s;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food2Stock -= itemQuantity;
                }
                else if (size == 'm' || size == 'M') {
                    unitPrice = food2m;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food2Stock -= itemQuantity;
                }
                else if (size == 'l' || size == 'L') {
                    unitPrice = food2l;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food2Stock -= itemQuantity;
                }

            }
            else if (itemCode == 'c' || itemCode == 'C') {
                foodName = food3;
                if (size == 's' || size == 'S') {
                    unitPrice = food3s;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food3Stock -= itemQuantity;
                }
                else if (size == 'm' || size == 'M') {
                    unitPrice = food3m;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food3Stock -= itemQuantity;
                }
                else if (size == 'l' || size == 'L') {
                    unitPrice = food3l;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food3Stock -= itemQuantity;
                }

            }
            else if (itemCode == 'd' || itemCode == 'D') {
                foodName = food4;
                if (size == 's' || size == 'S') {
                    unitPrice = food4s;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food4Stock -= itemQuantity;
                }
                else if (size == 'm' || size == 'M') {
                    unitPrice = food4m;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food4Stock -= itemQuantity;
                }
                else if (size == 'l' || size == 'L') {
                    unitPrice = food4l;
                    cout << setw(10) << left << "Enter quantity: " << endl;
                    cin >> itemQuantity;
                    food4Stock -= itemQuantity;
                }

            }
            else if (itemCode == 'e' || itemCode == 'E') {
                break;
            }
            unitPrice = setUnitPrice(price);

            double subtotal = itemQuantity * unitPrice;

            reciept // this is the accumulator for the reciept items
                << left << setw(15) << foodName
                << setw(10) << itemCode
                << setw(10) << size
                << setw(10) << itemQuantity
                << fixed << setprecision(2) << subtotal << endl;

            audit // this is the accumulator for the audit items
                << left << setw(15) << foodName
                << setw(10) << itemCode
                << setw(10) << size
                << right << setw(10) << itemQuantity << endl;

            totalCost += subtotal;

        } while (toupper(itemCode) != 'E' && (toupper(itemCode) == 'A' || toupper(itemCode) == 'B' || toupper(itemCode) == 'C' || toupper(itemCode) == 'D'));
        cout << setw(10) << left << "Are you a member? (y/n): " << endl;
        cin >> memberCheck;

        if (memberCheck == 'y' || memberCheck == 'Y')
        {
            totalCost = totalCost * 0.90;

        }

        cin.ignore();
        cout << setw(10) << left << "Enter cashier notes: " << endl;
        getline(cin, cashierNotes);
        cout << "How much do you want to tip" << endl;
        cout << "A. 15% = $" << fixed << setprecision(2) << totalCost * 0.15 << endl;
        cout << "B. 20% = $" << fixed << setprecision(2) << totalCost * 0.20 << endl;
        cout << "C. 25% = $" << fixed << setprecision(2) << totalCost * 0.25 << endl;
        cout << "D. Other" << endl;
        cout << "E. No Tip" << endl;
        cin >> tips;
        if (tips == 'a' || tips == 'A') {
            tipCost = totalCost * 0.15;
        }

        else if (tips == 'b' || tips == 'B') {
            tipCost = totalCost * 0.20;
        }

        else if (tips == 'c' || tips == 'C') {
            tipCost = totalCost * 0.25;
        }

        else if (tips == 'd' || tips == 'D') {
            cout << "Please enter how much you'd like to tip:" << endl;
            cin >> tipCost;
        }
        else if (tips == 'e' || tips == 'E') {
            tipCost = 0.00;
        }
        cout << "please enter customer's name:" << endl;
        cin >> customerName;
        
        ofstream receipt_fout;
        receipt_fout.open("Reciept.txt");

        cout << "\n----- RECEIPT -----\n";
        receipt_fout << "\n----- RECEIPT -----\n";

        cout << "Customer Name: " << customerName << endl;
        receipt_fout << "Customer Name: " << customerName << endl;

        cout << left << setw(15) << "Item"
            << setw(10) << "Code"
            << setw(10) << "Size"
            << setw(10) << "Qty"
            << setw(10) << "Subtotal" << endl;
        receipt_fout << left << setw(15) << "Item"
            << setw(10) << "Code"
            << setw(10) << "Size"
            << setw(10) << "Qty"
            << setw(10) << "Subtotal" << endl;

        cout << reciept.str(); // this makes the reciept items appear
        receipt_fout << reciept.str();

        cout << "Total: $" << fixed << setprecision(2) << totalCost << endl;
        receipt_fout << "Total: $" << fixed << setprecision(2) << totalCost << endl;

        cout << "\n----- INVENTORY AUDIT -----\n";
        receipt_fout << "\n----- INVENTORY AUDIT -----\n";

        cout << left
            << setw(15) << "Item"
            << setw(10) << "Code"
            << setw(10) << "Size"
            << right << setw(10) << "Qty" << endl;
        receipt_fout << left
            << setw(15) << "Item"
            << setw(10) << "Code"
            << setw(10) << "Size"
            << right << setw(10) << "Qty" << endl;

        cout << audit.str(); // this makes the inventory audit items appear
        receipt_fout << audit.str();

        stateTax = totalCost * 0.065;
        countyTax = totalCost * 0.005;
        municipalTax = totalCost * 0.02125;
        totalCost = (totalCost + stateTax + countyTax + municipalTax + tipCost);

        cout << "\n----- TAXES -----\n";
        receipt_fout << "\n----- TAXES -----\n";

        cout << left
            << setw(25) << "Tax"
            << setw(15) << "Percentage"
            << setw(10) << "Cost" << endl
            << setw(25) << "Arkansas State Tax:"
            << setw(15) << "6.5%"
            << setw(10) << fixed << setprecision(2) << stateTax << endl
            << setw(25) << "Faulkner County Tax:"
            << setw(15) << "0.5%"
            << setw(10) << fixed << setprecision(2) << countyTax << endl
            << setw(25) << "Conway Municipal Tax:"
            << setw(15) << "0.02125%"
            << setw(10) << fixed << setprecision(2) << municipalTax << endl;
        receipt_fout << left
            << setw(25) << "Tax"
            << setw(15) << "Percentage"
            << setw(10) << "Cost" << endl
            << setw(25) << "Arkansas State Tax:"
            << setw(15) << "6.5%"
            << setw(10) << fixed << setprecision(2) << stateTax << endl
            << setw(25) << "Faulkner County Tax:"
            << setw(15) << "0.5%"
            << setw(10) << fixed << setprecision(2) << countyTax << endl
            << setw(25) << "Conway Municipal Tax:"
            << setw(15) << "0.02125%"
            << setw(10) << fixed << setprecision(2) << municipalTax << endl;

        cout << left << setw(39) << "Subtotal + Tax: " << "$" << totalCost << endl;
        receipt_fout << left << setw(39) << "Subtotal + Tax: " << "$" << totalCost << endl;

        cout << left << "Loyalty Points: ";
        receipt_fout << left << "Loyalty Points: ";

        cout << left << setw(39) << "Subtotal + Tax: " << "$" << totalCost << endl;
        cout << left << "Loyalty Points: ";
        loyalty = totalCost / 3;
        grandTotal += totalCost;
        totalCustomers++;
        for (int count = 0; count < loyalty; count++) {
            cout << "*";
        }
        cout << endl << "is there another customer? (y/n)?" << endl;
            cin >> cashierResponse;
            if (cashierResponse == 'N' || cashierResponse == 'n') {
                anotherCustomer = false;
                cout << "Total Sales for the day: $" << grandTotal << endl
                    << "Total Customers for the day: " << totalCustomers << endl
                    << "Daily Inventory" << endl
                    << setw(20) << "Item" << setw(10) << "Start" << setw(10) << "Change" << setw(10) << "End" << endl
                    << setw(20) << food1 << setw(10) << 50 << setw(10) << food1Stock << 50 + (food1Stock) << endl
                    << setw(20) << food2 << setw(10) << 50 << setw(10) << food2Stock << 50 + (food2Stock) << endl
                    << setw(20) << food3 << setw(10) << 50 << setw(10) << food3Stock << 50 + (food3Stock) << endl
                    << setw(20) << food4 << setw(10) << 50 << setw(10) << food4Stock << 50 + (food4Stock) << endl;
            }
    }
}
double setUnitPrice(char itemCode, char size,
    double food1s, double food1m, double food1l,
    double food2s, double food2m, double food2l,
    double food3s, double food3m, double food3l,
    double food4s, double food4m, double food4l)
{
double price = 0.0;
    if (itemCode == 'a' || itemCode == 'A') {
        if (size == 's' || size == 'S')
            return price = food1s;
        else if (size == 'm' || size == 'M')
            return price = food1m;
        else if (size == 'l' || size == 'L')
            return price = food1l;
    }
    else if (itemCode == 'b' || itemCode == 'B') {
        if (size == 's' || size == 'S')
            return price = food2s;
        else if (size == 'm' || size == 'M')
            return price = food2m;
        else if (size == 'l' || size == 'L')
            return price = food2l;
    }
    else if (itemCode == 'c' || itemCode == 'C') {
        if (size == 's' || size == 'S')
            return price = food3s;
        else if (size == 'm' || size == 'M')
            return price = food3m;
        else if (size == 'l' || size == 'L')
            return price = food3l;
    }
    else if (itemCode == 'd' || itemCode == 'D') {
        if (size == 's' || size == 'S')
            return price = food4s;
        else if (size == 'm' || size == 'M')
            return price = food4m;
        else if (size == 'l' || size == 'L')
            return price = food4l;
    }

    return 0.0;
}