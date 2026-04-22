#include <iostream>
using namespace std;

class Base1 {
public:
    Base1() { cout << "Base1 Constructor\n"; }
    ~Base1() { cout << "Base1 Destructor\n"; }
};

class Derived1 : public Base1 {
    int* data;
public:
    Derived1(int n) {
        data = new int[n];
        cout << "Derived1 Constructor, allocated " << n << endl;
    }
    ~Derived1() {
        delete[] data;
        cout << "Derived1 Destructor, memory released\n";
    }
};

class Base2 {
public:
    Base2() { cout << "Base 2 Constructor\n"; }
    virtual ~Base2() { cout << "Base 2 Destructor\n"; }
};

class Derived2 : public Base2 {
    int* data;
public:
    Derived2(int n) {
        data = new int[n];
        cout << "Derived 2 Constructor, allocated " << n << endl;
    }
    ~Derived2() {
        delete[] data;
        cout << "Derived 2 Destructor, memory released\n";
    }
};

int main() {
    int n;
    cout << "Enter number of objects: ";
    cin >> n;

    cout << "\nWithout Virtual Destructor:\n";
    for(int i = 0; i < n; i++) {
        int size;
        cout << "Enter size for object " << i + 1 << ": ";
        cin >> size;
        Base1* b = new Derived1(size);
        delete b;
    }

    cout << "\nWith Virtual Destructor:\n";
    for(int i = 0; i < n; i++) {
        int size;
        cout << "Enter size for object " << i + 1 << ": ";
        cin >> size;
        Base2* b = new Derived2(size);
        delete b;
    }

    return 0;
}