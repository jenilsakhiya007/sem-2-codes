#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of attempts: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        try {
            int a, b;
            cout << "Enter two integers: ";
            if(!(cin >> a >> b))
                throw "Invalid Input";

            if(b == 0)
                throw "Division by zero";

            cout << "Result: " << (float)a / b << endl;
        }
        catch(const char* msg) {
            cout << "Error: " << msg << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    return 0;
}