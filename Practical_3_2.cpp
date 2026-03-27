#include <iostream>
using namespace std;
void iterative(int arr[] ,int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
        sum += *(arr + i);
    }
    cout << sum;
}
int recursive(int arr[],int size)
{
    if(size<1){
        return 1;
    }
    return *(arr+size)+recursive(arr,size-1);
}
int main()
{
    int n;
    cout << "Enter a numbers :";
    cin >> n;
    int *arr = new int[n];
    iterative(arr ,n);
    int result=recursive(arr,n-1);
    cout<<"\n"<<result;
    
    return 0;
}
