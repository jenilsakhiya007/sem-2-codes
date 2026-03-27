#include <iostream>
#include <string>
using namespace std;

class Bank
{
    long account_no;
    string holder_name;
    float balance;

public:
    static int count;

    Bank() {}

    static void users()
    {
        count++;
    }

    bool search(long);
    void add();
    void update();
    void Display() const;

    
    static void transfer(Bank b[], int total);
};

int Bank::count = 0;

bool Bank::search(long ac_no)
{
    return account_no == ac_no;
}

void Bank::add()
{
    cout << "Enter Account no: ";
    cin >> account_no;

    cout << "Enter Account holder name: ";
    cin.ignore();
    getline(cin, holder_name);

    cout << "Enter current Balance: ";
    cin >> balance;
}

void Bank::Display() const
{
    cout << "\nAccount No: " << account_no << endl;
    cout << "Account holder name: " << holder_name << endl;
    cout << "Current balance: " << balance << endl;
    cout << "Total Accounts: " << Bank::count << endl;
}

void Bank::update()
{
    cout << "Enter new Name: ";
    cin.ignore();
    getline(cin, holder_name);
}


void Bank::transfer(Bank b[], int total)
{
    long fromAcc, toAcc;
    float amount;

    cout << "Enter sender account no: ";
    cin >> fromAcc;

    cout << "Enter receiver account no: ";
    cin >> toAcc;

    cout << "Enter amount: ";
    cin >> amount;

    int fromIndex = -1, toIndex = -1;

 
    for (int i = 0; i < total; i++)
    {
        if (b[i].search(fromAcc))
            fromIndex = i;

        if (b[i].search(toAcc))
            toIndex = i;
    }

    
    if (fromIndex == -1)
    {
        cout << "Sender account not found!\n";
        return;
    }

    if (toIndex == -1)
    {
        cout << "Receiver account not found!\n";
        return;
    }

    if (fromAcc == toAcc)
    {
        cout << "Cannot transfer to same account!\n";
        return;
    }

    if (amount <= 0)
    {
        cout << "Invalid amount!\n";
        return;
    }

    if (b[fromIndex].balance < amount)
    {
        cout << "Insufficient balance!\n";
        return;
    }

  
    b[fromIndex].balance -= amount;
    b[toIndex].balance += amount;

    cout << "Money transferred successfully!\n";
}

int main()
{
    int choice, n, i;
    long acc;

    cout << "Enter number of accounts: ";
    cin >> n;

    Bank *b = new Bank[n];

    do
    {
        cout << "\n1. Add account";
        cout << "\n2. Update account";
        cout << "\n3. Display account";
        cout << "\n4. Transfer money";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (Bank::count < n)
            {
                b[Bank::count].add();
                Bank::users();
            }
            else
            {
                cout << "Account limit reached!\n";
            }
            break;

        case 2:
            cout << "Enter Account no: ";
            cin >> acc;
            for (i = 0; i < Bank::count; i++)
            {
                if (b[i].search(acc))
                {
                    b[i].update();
                    break;
                }
            }
            if (i == Bank::count)
                cout << "Account not found!\n";
            break;

        case 3:
            cout << "Enter Account no: ";
            cin >> acc;
            for (i = 0; i < Bank::count; i++)
            {
                if (b[i].search(acc))
                {
                    b[i].Display();
                    break;
                }
            }
            if (i == Bank::count)
                cout << "Account not found!\n";
            break;

        case 4:
            Bank::transfer(b, Bank::count);
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}