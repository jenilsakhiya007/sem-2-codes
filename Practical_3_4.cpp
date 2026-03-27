#include <iostream>
using namespace std;

template <typename T>
void display(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
T findMax(T arr[], int n)
{
    T max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template <typename T>
void reverseArray(T arr[], int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Integer Array";
        cout << "\n2. Float Array";
        cout << "\n3. Character Array";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Enter size: ";
            cin >> n;
            int arr[n];
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            cout << "Array: ";
            display(arr, n);

            cout << "Max: " << findMax(arr, n) << endl;

            cout << "Reversed: ";
            reverseArray(arr, n);
            
            break;
        }

        case 2:
        {
            int n;
            cout << "Enter size: ";
            cin >> n;
            float arr[n];
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            cout << "Array: ";
            display(arr, n);

            cout << "Max: " << findMax(arr, n) << endl;

            cout << "Reversed: ";
            reverseArray(arr, n);
            
            break;
        }

        case 3:
        {
            int n;
            cout << "Enter size: ";
            cin >> n;
            char arr[n];
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            cout << "Array: ";
            display(arr, n);

            cout << "Max: " << findMax(arr, n) << endl;

            cout << "Reversed: ";
            reverseArray(arr, n);
            
            break;
        }

        case 4:
            return 0;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}