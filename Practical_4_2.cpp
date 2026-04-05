#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    Point(int a, int b) {
        x = a;
        y = b;
    }

    Point* move(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

void update(Point* p) {
    p->move(5, 5);
}

int main() {
    int a,b;
    cout<<"Enter X and Y cordinate (Ex->2 7)"<<endl;
    cin>>a>>b;
    Point p(a, b);

    p.move(2, 2)->move(-1, -1);
    p.display();

    update(&p);
    p.display();

    return 0;
}