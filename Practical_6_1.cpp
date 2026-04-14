#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    double radius;
public:
    void setRadius(double r) {
       radius = r;
    }
    
};


class Circle : public Shape {
public:
    
    double getArea() const {
        return M_PI * radius * radius;
    }
};

int main() {
    int n;
    cout << "Enter number of circles: ";
    cin >> n;

    Circle circles[n];  
    for (int i = 0; i < n; i++) {
        double r;
        cout << "Enter radius of circle " << i + 1 << ": ";
        cin >> r;
        circles[i].setRadius(r);
    }

    cout << "\nAreas:\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1 << ": " << circles[i].getArea() << endl;
    }

    return 0;
}