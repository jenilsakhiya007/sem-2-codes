// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<iostream>
#include<string>
using namespace std;
class Account
{
    protected:
    long Account_no;
    long c_balance;
    public:
    Account(){}
    void Display();
    void Deposite();
    void Withdrawl();
    Account(long ac_no,long b)
    {
        Account_no=ac_no;
        c_balance=b;
    }

};
void Account::Deposite()
{
    long amount;
    cout<<"\nEnter amount :";
    cin>>amount;
    c_balance+=amount;
}
void Account::Withdrawl()
{
    long amount;
    cout<<"\nEnter amount :";
    cin>>amount;
    c_balance-=amount;
}
void Account::Display(){
    cout<<"\nAccount no : "<<Account_no;
    cout<<"\nCurrent Balance :"<<c_balance;
}



class Saving : public Account
{
   private:
        float rate;
   public:
       Saving(){}
       Saving(long ac_no,long b,float r):Account(ac_no,b)
       {
        rate=r;
       }
        void calculate();
        bool getID(long no)
        {
            return no==Account_no;
        }

};
class Current :public Account
{

};
int main()
{
    int n,i,choice;
    float r;
    long acc,bal,no;
    cout<<"Enter number of Accounts :";
    cin>>n;
    Saving s[n];
    do{
        cout<<"\n\n1.Add Account";
        cout<<"\n2.Deposite";
        cout<<"\n3.Withdrawl";
        cout<<"\n4.Display";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice :";
        cin>>choice;
        switch(choice)
        {
          case 1:
              for(i=0;i<n;i++)
              {
                  cout<<"\nEnter your Account number:";
                  cin>>acc;
                  cout<<"Enter your Balance:";
                  cin>>bal;
                  cout<<"Enter interest rate :";
                  cin>>r;
                  s[i]=Saving(acc,bal,r);
              }
              break;
          case 2:

               cout<<"\nEnter  your Account Number :";
               cin>>no;
               for(i=0;i<n;i++)
              {
                 if(s[i].getID(no))
                 {
                    s[i].Deposite();
                     break;
                 }

              }
              if(i==n){cout<<"\nAccount not Founded !";}
            break;
          case 3:

               cout<<"\nEnter  your Account Number :";
               cin>>no;
               for(i=0;i<n;i++)
              {
                 if(s[i].getID(no))
                 {
                    s[i].Withdrawl();
                     break;
                 }

              }
              if(i==n){cout<<"\nAccount not Founded !";}
            break;
          case 4:
              for(i=0;i<n;i++)
              {
                  s[i].Display();
              }
              break;

                break;
          default:
            cout<<"\nEnter valid choice";
        }
    }while(choice!=5);
    return 0;
}
