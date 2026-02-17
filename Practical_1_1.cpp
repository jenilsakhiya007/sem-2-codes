#include <iostream>
using namespace std;
class Bank_account
{
    char account_holder_name[30];
    long int account_no;
    long double balance;

public:
    void creat_account()
    {
        cout << "Enter an count no : ";
        cin >> account_no;
        cout << "Enter your name : ";
        cin >> account_holder_name;
        cout << "Enter your Balance :";
        cin >> balance;
    }
    char search(long int acno)
    {
        if (acno == account_no)
        {
            return 'v';
        }
        else
        {
            return 'i';
        }
    }
    void deposite()
    {
        int money;
        cout << "Enter Amount for Deposite :";
        cin >> money;
        balance += money;
    }
    void withdrawl()
    {
        int w;
        cout << "Enter Amount for Withdral : ";
        cin >> w;
        balance -= w;
    }
    void check_bl()
    {
        cout << "Your Balance is :" << balance;
    }
};
int main()
{
    Bank_account b[100];
    long int accno;
    int t = 0, i;

L:
    cout << "\n1.Creat Account\n";
    cout << "2.Deposite\n";
    cout << "3.Withdrawl\n";
    cout << "4.Check Balance\n";
    cout << "5.Exit\n";
    int choice;
    cout << "Enter a choice :";
    cin >> choice;

    switch (choice)
    {
    case 1:
        b[t].creat_account();
        t++;
        goto L;
    case 2:
        cout << "Enter an Account no :";
        cin >> accno;
        for (i = 0; i < t; i++)
        {
            if (b[i].search(accno) == 'v')
            {
                b[i].deposite();
                break;
            }
        }
        if (i == t)
        {
            cout << "Account Not found !";
        }
        goto L;

    case 3:
        cout << "Enter an Account no :";
        cin >> accno;
        for (i = 0; i < t; i++)
        {
            if (b[i].search(accno) == 'v')
            {
                b[i].withdrawl();
                break;
            }
        }
        if (i == t)
        {
            cout << "Account Not found !";
        }
        goto L;

    case 4:
        cout << "Enter an Account no :";
        cin >> accno;
        for (i = 0; i < t; i++)
        {
            if (b[i].search(accno) == 'v')
            {
                b[i].check_bl();
                break;
            }
        }
        if (i == t)
        {
            cout << "Account Not found !\n";
        }
        goto L;
    case 5:
        cout << "Thanks for visite\n";
        break;

    default:
        cout << "Enter a valid choice (from 1 to 5)";
        goto L;
    }

    return 0;
}