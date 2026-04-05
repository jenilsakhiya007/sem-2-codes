#include <iostream>
#include <fstream>
using namespace std;

void addItem() {
    ofstream file("inventory.txt", ios::app);

    string name;
    int quantity;
    float price;

    cin.ignore();  

    cout << "Enter item name: ";
    getline(cin, name);

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter price: ";
    cin >> price;

    file << name << "," << quantity << "," << price << endl;

    file.close();
}

void viewItems() {
    ifstream file("inventory.txt");

    string line;

    cout << "\n--- Inventory Items ---\n";

    while (getline(file, line)) {
        cout << line << endl;   
    }

    file.close();
}

void searchItem() {
    ifstream file("inventory.txt");

    string searchName;
    cin.ignore();

    cout << "Enter item name to search: ";
    getline(cin, searchName);

    string name;
    int quantity;
    float price;
    char comma;

    bool found = false;

    while (getline(file, name, ',') && file >> quantity >> comma >> price) {
        file.ignore(); // skip newline

        if (name == searchName) {
            cout << "\nItem Found!\n";
            cout << "Name: " << name
                 << ", Quantity: " << quantity
                 << ", Price: " << price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item not found!\n";
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Item\n";
        cout << "2. View All Items\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}