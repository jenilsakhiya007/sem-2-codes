#include<iostream>
using namespace std;

int main(){
    int m,n;

    cout<<"Enter size of First array :";
    cin>>n;
    int* arr_1 = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr_1[i];
    }

    cout<<"\nEnter size of Second array :";
    cin>>m;
    int* arr_2 = new int[m];

    for(int i=0;i<m;i++)
    {
        cin>>arr_2[i];
    }

    int* newarr = new int[m+n];

    int i=0, j=0, k=0;

    while(i<n && j<m)
    {
        if(arr_1[i] < arr_2[j])
            newarr[k++] = arr_1[i++];
        else
            newarr[k++] = arr_2[j++];
    }

    while(i<n)
    {
        newarr[k++] = arr_1[i++];
    }

    while(j<m)
    {
        newarr[k++] = arr_2[j++];
    }

    cout<<"\nMerged array:\n";
    for(int i=0;i<m+n;i++)
    {
        cout<<newarr[i]<<" ";
    }

    delete[] arr_1;
    delete[] arr_2;
    delete[] newarr;

    return 0;
}