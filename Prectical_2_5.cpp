#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Loan
{
    int loan_id;
    string name;
    double amount;
    double rate;
    int tenure;

public:
    Loan()
    {
        loan_id = 0;
        name = "";
        amount = 0;
        rate = 0;
        tenure = 0;
    }

    Loan(int id, string n, double a, double r, int t)
    {
        loan_id = id;
        name = n;
        amount = a;
        rate = r;
        tenure = t;
    }

    void input()
    {
        cout << "Enter Loan ID: ";
        cin >> loan_id;
        cout << "Enter Applicant Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Loan Amount: ";
        cin >> amount;
        cout << "Enter Annual Interest Rate: ";
        cin >> rate;
        cout << "Enter Tenure (months): ";
        cin >> tenure;
    }

    double calculateEMI()
    {
        double R = rate / (12 * 100);
        double T = tenure;
        return (amount * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
    }

    void display()
    {
        cout << "\nLoan ID: " << loan_id << endl;
        cout << "Applicant Name: " << name << endl;
        cout << "Loan Amount: " << amount << endl;
        cout << "Interest Rate: " << rate << endl;
        cout << "Tenure: " << tenure << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
    }
};

int main()
{
    int n, choice, i;
    cout << "Enter number of users: ";
    cin >> n;

    Loan *l = new Loan[n];
    int count = 0;

    do
    {
        cout << "\n1. Add Loan";
        cout << "\n2. Display All Loans";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < n)
            {
                l[count].input();
                count++;
            }
            else
            {
                cout << "Limit reached\n";
            }
            break;

        case 2:
            for (i = 0; i < count; i++)
            {
                l[i].display();
            }
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 3);

    return 0;
}