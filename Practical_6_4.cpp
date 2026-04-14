#include <iostream>
using namespace std;

#define MAX 100

class Account
{
protected:
    long acc_no;
    double balance;

    double history[100];
    int h_count;

public:
    Account()
    {
        h_count = 0;
    }

    Account(long a, double b)
    {
        acc_no = a;
        balance = b;
        h_count = 0;
    }

    virtual void deposit()
    {
        double amt;
        cout << "Enter amount: ";
        cin >> amt;

        if (amt <= 0)
        {
            cout << "Invalid amount!\n";
            return;
        }

        balance += amt;
        history[h_count++] = amt;
    }

    virtual void withdraw()
    {
        double amt;
        cout << "Enter amount: ";
        cin >> amt;

        if (amt > balance)
        {
            cout << "Insufficient balance!\n";
            return;
        }

        balance -= amt;
        history[h_count++] = -amt;
    }

    void undo()
    {
        if (h_count == 0)
        {
            cout << "No transaction!\n";
            return;
        }

        double last = history[--h_count];
        balance -= last;

        cout << "Undo successful!\n";
    }

    void showHistory()
    {
        cout << "\nTransaction History:\n";
        for (int i = 0; i < h_count; i++)
        {
            cout << history[i] << endl;
        }
    }

    virtual void display()
    {
        cout << "\nAccount No: " << acc_no;
        cout << "\nBalance: " << balance << endl;
    }

    bool match(long no)
    {
        return acc_no == no;
    }
};


class Saving : public Account
{
    float rate;

public:
    Saving() {}

    Saving(long a, double b, float r) : Account(a, b)
    {
        rate = r;
    }

    void display()
    {
        Account::display();
        cout << "Interest Rate: " << rate << endl;
    }
};
class Current : public Account
{
    double overdraft;

public:
    Current() {}

    Current(long a, double b, double od) : Account(a, b)
    {
        overdraft = od;
    }
    void withdraw()
    {
        double amt;
        cout << "Enter amount: ";
        cin >> amt;

        if (amt > balance + overdraft)
        {
            cout << "Overdraft limit exceeded!\n";
            return;
        }
        balance -= amt;
        history[h_count++] = -amt;
    }

    void display()
    {
        Account::display();
        cout << "Overdraft Limit: " << overdraft << endl;
    }
};

int main()
{
    Account* accounts[MAX];   
    int count = 0;
    int choice;

    do
    {
        cout << "\n1. Add Saving Account";
        cout << "\n2. Add Current Account";
        cout << "\n3. Deposit";
        cout << "\n4. Withdraw";
        cout << "\n5. Display All";
        cout << "\n6. Transaction History";
        cout << "\n7. Undo";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        long no;

        switch (choice)
        {
        case 1:
        {
            if (count >= MAX)
            {
                cout << "Limit reached!\n";
                break;
            }

            long a;
            double b;
            float r;

            cout << "Enter acc no, balance, rate: ";
            cin >> a >> b >> r;

            accounts[count++] = new Saving(a, b, r);
            break;
        }

        case 2:
        {
            if (count >= MAX)
            {
                cout << "Limit reached!\n";
                break;
            }

            long a;
            double b, od;

            cout << "Enter acc no, balance, overdraft: ";
            cin >> a >> b >> od;

            accounts[count++] = new Current(a, b, od);
            break;
        }

        case 3:
            cout << "Enter account no: ";
            cin >> no;

            for (int i = 0; i < count; i++)
            {
                if (accounts[i]->match(no))
                {
                    accounts[i]->deposit();
                    break;
                }
            }
            break;

        case 4:
            cout << "Enter account no: ";
            cin >> no;

            for (int i = 0; i < count; i++)
            {
                if (accounts[i]->match(no))
                {
                    accounts[i]->withdraw();
                    break;
                }
            }
            break;

        case 5:
            for (int i = 0; i < count; i++)
            {
                accounts[i]->display();
            }
            break;

        case 6:
            cout << "Enter account no: ";
            cin >> no;

            for (int i = 0; i < count; i++)
            {
                if (accounts[i]->match(no))
                {
                    accounts[i]->showHistory();
                    break;
                }
            }
            break;

        case 7:
            cout << "Enter account no: ";
            cin >> no;

            for (int i = 0; i < count; i++)
            {
                if (accounts[i]->match(no))
                {
                    accounts[i]->undo();
                    break;
                }
            }
            break;

        }

    } while (choice != 8);

    return 0;
}