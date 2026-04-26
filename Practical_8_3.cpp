#include <iostream>
using namespace std;

string logs[100];
int idx = 0;

class BankAccount {
    double balance;
public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amt) {
        logs[idx++] = "Enter deposit()";
        if(amt <= 0)
            throw "Invalid deposit amount";
        balance += amt;
        logs[idx++] = "Deposit successful";
        logs[idx++] = "Exit deposit()";
    }

    void withdraw(double amt) {
        logs[idx++] = "Enter withdraw()";
        if(amt > balance)
            throw "Insufficient balance";
        if(amt <= 0)
            throw "Invalid withdrawal amount";
        balance -= amt;
        logs[idx++] = "Withdrawal successful";
        logs[idx++] = "Exit withdraw()";
    }

    double getBalance() {
        return balance;
    }
};

void processTransaction(BankAccount &acc, int type, double amt) {
    logs[idx++] = "Enter processTransaction()";
    switch(type) {
        case 1:
            acc.deposit(amt);
            break;
        case 2:
            acc.withdraw(amt);
            break;
        default:
            throw "Invalid choice";
    }
    logs[idx++] = "Exit processTransaction()";
}

int main() {
    double initial;
    cout << "Enter initial balance: ";
    cin >> initial;

    BankAccount acc(initial);

    int n;
    cout << "Enter number of transactions: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int type;
        double amt;
        cout << "Enter 1 for deposit, 2 for withdraw: ";
        cin >> type;
        cout << "Enter amount: ";
        cin >> amt;

        try {
            processTransaction(acc, type, amt);
        }
        catch(const char* msg) {
            logs[idx++] = "Exception caught in main";
            cout << "Error: " << msg << endl;
        }
    }

    cout << "\nFinal Balance: " << acc.getBalance() << endl;

    cout << "\nLogs:\n";
    for(int i = 0; i < idx; i++) {
        cout << logs[i] << endl;
    }

    return 0;
}