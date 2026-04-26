#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    set<int> s;

    for(int i = 0; i < n; i++) {
        int x;
        cout << "Enter element: ";
        cin >> x;
        s.insert(x);
    }

    cout << "\nUnique elements:\n";
    for(auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}