#include <iostream>
using namespace std;

class Shape {
public:
    virtual float Area() = 0;
};

class Rectangle : public Shape {
public:
    float l, w;
    Rectangle(float a, float b) {
        l = a;
        w = b;
    }
    float Area() {
        return l * w;
    }
};

class Circle : public Shape {
public:
    float r;
    Circle(float a) {
        r = a;
    }
    float Area() {
        return 3.14159 * r * r;
    }
};

int main() {
    int n;
    cout << "Enter number of shapes: ";
    cin >> n;

    Shape* dyn[100];
    Shape* stat[100];

    for(int i = 0; i < n; i++) {
        int choice;
        cout << "Enter 1 for Rectangle, 2 for Circle: ";
        cin >> choice;

        if(choice == 1) {
            float l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            dyn[i] = new Rectangle(l, w);
            stat[i] = new Rectangle(l, w);
        } else {
            float r;
            cout << "Enter radius: ";
            cin >> r;
            dyn[i] = new Circle(r);
            stat[i] = new Circle(r);
        }
    }

    cout << "\nDynamic Storage Areas:\n";
    for(int i = 0; i < n; i++) {
        cout << dyn[i]->Area() << endl;
    }

    cout << "\nStatic Storage Areas:\n";
    for(int i = 0; i < n; i++) {
        cout << stat[i]->Area() << endl;
    }

    return 0;
}