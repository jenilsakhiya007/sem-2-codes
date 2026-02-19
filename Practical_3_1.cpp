#include<iostream>
#include<string>
using namespace std;
class Employee
{
    string name;
    long salary;
    int bonus;

    public:
        Employee(){}
        Employee(string n,long s,int b)
        {
         name = n;
         salary = s;
         bonus = b;
        }

         long c_salary();
         void display();
};
inline long Employee::c_salary()
{
  long total_salary = salary+bonus;
  return total_salary;

}
void Employee::display()
{
    cout<<"\nEmployee Name :"<<name<<endl;
    cout<<"Total Salary :"<<c_salary()<<endl;
}
int main()
{
    Employee e[10];
    int i,b,E;
    long s;string n;
    cout<<"Enter number of Employee :";
    cin>>E;
    for(i=0;i<E;i++)
    {
        cout<<"Enter name of "<<i+1<<"\tEmployee :";
        cin.ignore();
        getline(cin,n);
        cout<<"Enter Salary :";
        cin>>s;
        cout<<"Enter Bonus amount:";
        cin>>b;
        e[i]=Employee(n,s,b);
        cout<<endl;
    }
    cout<<"Displaying Employees Detailes....\n";
    for(i=0;i<E;i++)
    {
        e[i].display();
    }

    return 0;
}
