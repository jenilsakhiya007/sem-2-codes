#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cout << "Enter element: ";
        cin >> x;
        v.push_back(x);
    }

    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());

    cout << "\nUsing reverse():\n";
    for(auto it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }

    vector<int> v2 = v;
    auto start = v2.begin();
    auto end = v2.end() - 1;

    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    cout << "\n\nManual reverse:\n";
    for(auto it = v2.begin(); it != v2.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}