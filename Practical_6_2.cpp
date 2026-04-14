#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
    void DisplayPerson()
    {
        cout << "Name :" << name << endl;
        cout << "Age :" << age << endl;
    }
};
class Employee : public Person
{
protected:
    int employee_id;

public:
    Employee(string n, int a, int id) : Person(n, a)
    {
        employee_id = id;
    }
    void DisplayEmployee()
    {
        DisplayPerson();
        cout << "Employee Id :" << employee_id << endl;
    }
};
class Manager : public Employee
{
private:
    string department;

public:
    Manager() : Employee(" ", 0, 0)
    {
        department = " ";
    };
    Manager(string n, int a, int id, string dept) : Employee(n, a, id)
    {
        department = dept;
    }
    void DisplayManager()
    {
        DisplayEmployee();
        cout << "Department :" << department << endl;
        cout << endl;
    }
};
int main()
{
    int size, i;
    cout << "Enter a number of employees :";
    cin >> size;
    Manager m[size];

    for (i = 0; i < size; i++)
    {
        string na, dept;
        int a, id;
        cout << "Emter name of " << i + 1 << " Employee :";
        cin.ignore();
        getline(cin, na);
        cout << "Emter age of Employee :";
        cin >> a;
        cout << "Emter Employee Id:";
        cin >> id;
        cout << "Emter Department :";
        cin.ignore();
        getline(cin, dept);
        cout << endl;

        m[i] = Manager(na, a, id, dept);
    }
    for (i = 0; i < size; i++)
    {
        m[i].DisplayManager();
    }
    return 0;
}