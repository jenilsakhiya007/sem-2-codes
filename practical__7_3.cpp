#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;

class Celsius {
public:
    float temp;
    Celsius() {}
    Celsius(float t) { temp = t; }
    operator Fahrenheit();
    bool operator==(Celsius c) {
        return temp == c.temp;
    }
};

class Fahrenheit {
public:
    float temp;
    Fahrenheit() {}
    Fahrenheit(float t) { temp = t; }
    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }
    bool operator==(Fahrenheit f) {
        return temp == f.temp;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main() {
    int n;
    cout << "Enter number of values: ";
    cin >> n;

    queue<Celsius> q;
    Celsius arr[100];

    for(int i = 0; i < n; i++) {
        float c;
        cout << "Enter temperature in Celsius: ";
        cin >> c;
        Celsius c1(c);
        q.push(c1);
        arr[i] = c1;
    }

    cout << "\nQueue Conversion (Celsius to Fahrenheit):\n";
    while(!q.empty()) {
        Celsius c = q.front();
        q.pop();
        Fahrenheit f = c;
        cout << f.temp << endl;
    }

    cout << "\nArray Conversion (Celsius to Fahrenheit):\n";
    for(int i = 0; i < n; i++) {
        Fahrenheit f = arr[i];
        cout << f.temp << endl;
    }

    float a, b;
    cout << "\nEnter two Celsius values to compare: ";
    cin >> a >> b;

    Celsius c1(a), c2(b);

    if(c1 == c2)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    return 0;
}