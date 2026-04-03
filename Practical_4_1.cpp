#include <iostream>
using namespace std;
class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray() {
        arr = nullptr;
        size = 0;
    }
    
    void insert(int value) {
        int* newArr = new int[size + 1];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        newArr[size] = value;

        delete[] arr;
        arr = newArr;
        size++;
    }
    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position\n";
            return;
        }
        int* newArr = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != pos) {
                newArr[j++] = arr[i];
            }
        }

        delete[] arr;
        arr = newArr;
        size--;
    }

    // Display array
    void display() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray da;

    da.insert(10);
    da.insert(20);
    da.insert(30);

    cout << "Array: ";
    da.display();

    da.deleteAt(1);

    cout << "After deletion: ";
    da.display();

    return 0;
}