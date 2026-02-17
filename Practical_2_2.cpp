#include<iostream>
#include<string>
using namespace std;
class Student
{
    int roll;
    string name;
    int mark_1;
    int mark_2;
    int mark_3;
    public:
    Student( )
    {     
         cout<<"Enter a roll no :";
         cin>>roll;
         cin.ignore();
         cout<<"Enter a name  :";
         getline(cin,name);
         cout<<"Enter a marks of subject 1 :";
         cin>>mark_1;
         cin.ignore();
         cout<<"Enter a marks of subject 2 :";
         cin>>mark_2;
         cin.ignore();
         cout<<"Enter a marks of subject 3 :";
         cin>>mark_3;
         cin.ignore();
         cout<<endl;
        
    }
         void display();

};
void Student::display(){
       cout<<"\nRoll no :"<<roll<<endl;
       cout<<"Name of student :"<<name<<endl;
       cout<<"mark of sub 1 :"<<mark_1<<endl;
       cout<<"mark of sub 2 :"<<mark_2<<endl;
       cout<<"mark of sub 3 :"<<mark_3<<endl;
       cout<<"Avarage of marks :"<<(mark_1+mark_2+mark_3)/3<<"%"<<endl;
       
    
}

int main()
{
   
    int i;
    Student s[2];
    
     cout<<"Student Report.....\n";

    for(i=0;i<2;i++){
     s[i].display();
    }
     
}
