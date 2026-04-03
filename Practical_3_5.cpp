#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int rec_1(int num){
if(num==0){return 0;}
return (num%10)+rec_1(num/10);
}
int main()
{
    string  n,rp="";
    int i,k;
    cout<<"Enter an number :";
    cin>>n;
    cout<<"Enter k :";
    cin>>k;
    for (i=0;i<k;i++)
    {
       rp +=n;
    }
    cout<<rp;
    int l=rp.length();
    long int num=stoi(rp);
    
   L: long int result_1=rec_1(num);
   
    if(abs(result_1)<10){
        cout<<"\nSuper digit is :"<<result_1;
    }
     else{ num=result_1; goto L;}
   
    return 0;
}
