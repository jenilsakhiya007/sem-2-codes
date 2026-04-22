#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException {};

int main() {
    int n;
    cout << "Enter number of inputs: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        try {
            double num;
            cout << "Enter number: ";
            cin >> num;

            if(num < 0)
                throw NegativeNumberException();

            cout << "Square root: " << sqrt(num) << endl;
        }
        catch(NegativeNumberException) {
            cout << "Error: Negative number not allowed\n";
        }
    }

    return 0;
}