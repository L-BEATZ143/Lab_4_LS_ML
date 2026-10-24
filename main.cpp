#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <fstream>

using namespace std; //Prevents the tedium of typing std:: 

double setUnitPrice(char itemCode, char size,
double food1s, double food1m, double food1l,
double food2s, double food2m, double food2l,
double food3s, double food3m, double food3l,
double food4s, double food4m, double food4l); // Neccesary to apply to the Main and setUnitPrice functions
void initializeFood(
    string& food1, string& food2, string& food3, string& food4,
    double& food1s, double& food1m, double& food1l,
    double& food2s, double& food2m, double& food2l,
    double& food3s, double& food3m, double& food3l,
    double& food4s, double& food4m, double& food4l);
ostringstream& foodMenu(ostringstream& menu,
    string food1, double food1s, double food1m, double food1l,
    string food2, double food2s, double food2m, double food2l,
    string food3, double food3s, double food3m, double food3l,
    string food4, double food4s, double food4m, double food4l);
ostringstream& auditReciept(ostringstream& audit, ostringstream& reciept);
int main() {
    string foodName; //holds the name of the food set by the item code
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
    double dayTotal = 0; //end of day total
    int totalCustomers = 0;
    bool anotherCustomer;
    char cashierResponse;
    int food1Stock = 0;
    int food2Stock = 0;
    int food3Stock = 0;
    int food4Stock = 0;
    anotherCustomer = true;
    string food1, food2, food3, food4;
    double food1s, food1m, food1l, food2s, food2m, food2l, food3s, food3m, food3l, food4s, food4m, food4l;
    ostringstream menu;

    initializeFood(food1, food2, food3, food4,
    food1s, food1m, food1l,
    food2s, food2m, food2l,
    food3s, food3m, food3l,
    food4s, food4m, food4l);

    while (anotherCustomer) {
        loyalty = 0;
        foodMenu(menu,
            food1, food1s, food1m, food1l,
            food2, food2s, food2m, food2l,
            food3, food3s, food3m, food3l,
            food4, food4s, food4m, food4l);

        cout << menu.str();        
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
            if (itemCode == 'a' || itemCode == 'A') {
                foodName = food1;
            }
            else if (itemCode == 'b' || itemCode == 'B') {
                foodName = food2;
            }
            else if (itemCode == 'c' || itemCode == 'C') {
                foodName = food3;
            }
                else if (itemCode == 'd' || itemCode == 'D') {
                foodName = food4;
                }
            else{
                    cout << "Invalid item code." << endl;
                continue;
                }

                unitPrice = setUnitPrice(itemCode, size,
                    food1s, food1m, food1l,
                    food2s, food2m, food2l,
                    food3s, food3m, food3l,
                    food4s, food4m, food4l);

                cout << "Enter quantity: " << endl;
                cin >> itemQuantity;

                double subtotal = itemQuantity * unitPrice;

            auditReciept(audit, reciept);

            totalCost += subtotal;
            if (toupper(itemCode) == 'A') {
                food1Stock -= itemQuantity;
            }
            else if (toupper(itemCode) == 'B') {
                food2Stock -= itemQuantity;
            }
            else if (toupper(itemCode) == 'C') {
                food3Stock -= itemQuantity;
            }
            else if (toupper(itemCode) == 'D') {
                food4Stock -= itemQuantity;
            }
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
        dayTotal += totalCost;
        totalCustomers++;
        for (int count = 0; count < loyalty; count++) {
            cout << "*";
        }
        cout << endl << "is there another customer? (y/n)?" << endl;
            cin >> cashierResponse;
            if (cashierResponse == 'N' || cashierResponse == 'n') {
                anotherCustomer = false;
                cout << "Total Sales for the day: $" << dayTotal << endl
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
// Functions begin
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

    return price;
}
void initializeFood(string &food1, string &food2, string &food3, string &food4,
    double &food1s, double &food1m, double &food1l, 
    double &food2s, double &food2m, double &food2l, 
    double &food3s, double &food3m, double &food3l,
    double &food4s, double &food4m, double &food4l)
    {
    ifstream inputFile("menu_text.txt"); //marks "menu_text.txt" for file to read from
    getline(inputFile, food1); //sets food item 1 to the item specified in the file
    inputFile >> food1s >> food1m >> food1l; //sets the prices for food item 1's small, medium, and large options
    inputFile.ignore(); //resets for next item

    getline(inputFile, food2); //sets food item 2 to the item specified in the file
    inputFile >> food2s >> food2m >> food2l; //sets the prices for food item 2's small, medium, and large options
    inputFile.ignore(); //resets for next item

    getline(inputFile, food3); //sets food item 3 to the item specified in the file
    inputFile >> food3s >> food3m >> food3l; //sets the prices for food item 3's small, medium, and large options
    inputFile.ignore(); //resets for next item

    getline(inputFile, food4); //sets food item 4 to the item specified in the file
    inputFile >> food4s >> food4m >> food4l; //sets the prices for food item 4's small, medium, and large options
    inputFile.ignore(); //possibly unneccesary? test to see
    inputFile.close();
    
}
ostringstream& foodMenu(ostringstream& menu,
    string food1, double food1s, double food1m, double food1l,
    string food2, double food2s, double food2m, double food2l,
    string food3, double food3s, double food3m, double food3l,
    string food4, double food4s, double food4m, double food4l)
    {
    menu
        << setw(15) << left << "Items"
        << setw(15) << "Small (S)"
        << setw(15) << "Medium (M)"
        << setw(15) << "Large (L)" << endl
        << setw(2) << left << "A. " << setw(13) << food1
        << setw(15) << fixed << setprecision(2) << food1s
        << setw(15) << fixed << setprecision(2) << food1m
        << setw(15) << fixed << setprecision(2) << food1l << endl
        << setw(2) << left << "B. " << setw(13) << food2
        << setw(15) << fixed << setprecision(2) << food2s
        << setw(15) << fixed << setprecision(2) << food2m
        << setw(15) << fixed << setprecision(2) << food2l << endl
        << setw(2) << left << "C. " << setw(13) << food3
        << setw(15) << fixed << setprecision(2) << food3s
        << setw(15) << fixed << setprecision(2) << food3m
        << setw(15) << fixed << setprecision(2) << food3l << endl
        << setw(2) << left << "D. " << setw(13) << food4
        << setw(15) << fixed << setprecision(2) << food4s
        << setw(15) << fixed << setprecision(2) << food4m
        << setw(15) << fixed << setprecision(2) << food4l << endl
        << "E. Checkout" << endl;
    return menu;
}
ostringstream& auditReciept(ostringstream& audit, ostringstream& reciept, string foodName, char itemCode, char size, int itemQuantity, double subtotal)
    {
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
    return audit;
}