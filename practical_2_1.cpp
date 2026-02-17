#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }

    void display(int index) {
        cout << "\nRectangle " << index + 1 << " Details:\n";
        cout << "Length    : " << length << endl;
        cout << "Width     : " << width << endl;
        cout << "Area      : " << area() << endl;
        cout << "Perimeter : " << perimeter() << endl;
    }
};

int main() {
    int  choice, idx;
    double l, w;

    
    Rectangle rect[10];   // array of objects

    do {
        cout << "\n----- Rectangle Menu -----\n";
        cout << "1. Set / Update Rectangle Dimensions\n";
        cout << "2. Calculate Area of a Rectangle\n";
        cout << "3. Calculate Perimeter of a Rectangle\n";
        cout << "4. Display All Rectangles\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter rectangle number (from 1 to 10) : ";
            cin >> idx;

            if (idx < 1 || idx > 10) {
                cout << "Invalid rectangle number!\n";
                break;
            }

            cout << "Enter length: ";
            cin >> l;
            cout << "Enter width: ";
            cin >> w;

            rect[idx - 1].setDimensions(l, w);
            cout << "Dimensions updated.\n";
            break;

        case 2:
            cout << "Enter rectangle number (from 1 to 10) : ";
            cin >> idx;

            if (idx < 1 || idx > 10) {
                cout << "Invalid rectangle number!\n";
                break;
            }

            cout << "Area = " << rect[idx - 1].area() << endl;
            break;

        case 3:
            cout << "Enter rectangle number : ";
            cin >> idx;

            if (idx < 1 || idx > 10) {
                cout << "Invalid rectangle number!\n";
                break;
            }

            cout << "Perimeter = " << rect[idx - 1].perimeter() << endl;
            break;

        case 4:
            for (int i = 0; i < 10; i++) {
                rect[i].display(i);
            }
            break;

        case 5:
            cout << "Thank you for visiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
