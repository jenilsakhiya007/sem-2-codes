#include<iostream>
#include<complex>
using namespace std;
class Complex
{
    double imaginary;
    double real;
    public:
    Complex(){}
    void setdata(double i, double r){
        imaginary = i ;
        real = r;
    }
    void show()
    {
        cout<<"Result is = "<<real<<"+"<<imaginary<<"i";
    }
    Complex operator +(Complex obj)
    {
        Complex temp;
        temp.imaginary = imaginary+obj.imaginary;
        temp.real = real+obj.real; 
        return  temp;
    }

};
int main()
{
    double i, r ,i2, r2;
    Complex c1,c2,c3;
    
        cout<<"Enter 1st real number :";
        cin>>r;
        cout<<"Enter 1st Imaginary number :";
        cin>>i;
        c1.setdata(i,r);
         cout<<"Enter 2nd real number :";
         cin>>r2;
         cout<<"Enter 2nd Imaginary number :";
         cin>>i2;
         c2.setdata(i,r);
         c3=c1+c2;
    
        c3.show();
    

    return 0;
}


