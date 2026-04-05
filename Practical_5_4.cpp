#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream& out)
{
    cout << "Rs ";
    return out;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    string name[n];
    int marks[n];
    double fees[n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter name: ";
        cin >> name[i];

        cout << "Enter marks: ";
        cin >> marks[i];

        cout << "Enter fees: ";
        cin >> fees[i];
    }

    cout << "\n";
    cout << setw(10) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Fees" << endl;

    cout << setfill('-') << setw(35) << "-" << endl;
    cout << setfill(' ');

    for(int i = 0; i < n; i++)
    {
        cout << setw(10) << name[i]
             << setw(10) << marks[i]
             << setw(10) << currency << fixed << setprecision(2) << fees[i]
             << endl;
    }

    return 0;
}