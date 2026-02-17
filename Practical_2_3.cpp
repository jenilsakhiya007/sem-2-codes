#include <iostream>
#include <string>
using namespace std;

class DigitalAccount
{
public:
    string name;
    int accountID;
    double balance;

    void create()
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account ID: ";
        cin >> accountID;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        if (balance < 0)
            balance = 0;
    }
    int acID(){
        return accountID;
    }

    void deposit()
    {
        double amount;
        cout << "Enter Deposit Amount: ";
        cin >> amount;

        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid deposit amount\n";
    }

    void withdraw()
    {
        double amount;
        cout << "Enter Withdrawal Amount: ";
        cin >> amount;

        if (amount > balance)
            cout << "Insufficient balance\n";
        else if (amount <= 0)
            cout << "Invalid withdrawal amount\n";
        else
            balance -= amount;
    }

    void display()
    {
        cout << "Customer Name: " << name << endl;
        cout << "Account ID: " << accountID << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    DigitalAccount accounts[100];
    int count = 0;
    int choice, id, i;

    do
    {
        cout << "\n1. Create Account";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Display Account";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            accounts[count].create();
            count++;
            break;

        case 2:
            cout << "Enter Account ID: ";
            cin >> id;
            for (i = 0; i < count; i++)
            {
                if (accounts[i].acID() == id)
                {
                    accounts[i].deposit();
                    break;
                }
            }
            break;

        case 3:
            cout << "Enter Account ID: ";
            cin >> id;
            for (i = 0; i < count; i++)
            {
                if (accounts[i].accountID == id)
                {
                    accounts[i].withdraw();
                    break;
                }
            }
            break;

        case 4:
            cout << "Enter Account ID: ";
            cin >> id;
            for (i = 0; i < count; i++)
            {
                if (accounts[i].accountID == id)
                {
                    accounts[i].display();
                    break;
                }
            }
            break;

        case 5:
            cout << "BY BY..\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
