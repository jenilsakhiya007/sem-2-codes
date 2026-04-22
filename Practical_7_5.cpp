#include <iostream>
#include <vector>
using namespace std;

class Student {
protected:
    float marks;
public:
    virtual void getData() = 0;
    virtual void computeGrade() = 0;
};

class Undergraduate : public Student {
public:
    void getData() {
        cout << "Enter marks for Undergraduate: ";
        cin >> marks;
    }
    void computeGrade() {
        if(marks >= 75) cout << "Grade: A\n";
        else if(marks >= 60) cout << "Grade: B\n";
        else if(marks >= 50) cout << "Grade: C\n";
        else cout << "Grade: F\n";
    }
};

class Postgraduate : public Student {
public:
    void getData() {
        cout << "Enter marks for Postgraduate: ";
        cin >> marks;
    }
    void computeGrade() {
        if(marks >= 80) cout << "Grade: A\n";
        else if(marks >= 65) cout << "Grade: B\n";
        else if(marks >= 55) cout << "Grade: C\n";
        else cout << "Grade: F\n";
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student*> students;

    for(int i = 0; i < n; i++) {
        int choice;
        cout << "Enter 1 for Undergraduate, \n2 for Postgraduate: ";
        cin >> choice;

        Student* s;
        if(choice == 1)
            s = new Undergraduate();
        else
            s = new Postgraduate();

        s->getData();
        students.push_back(s);
    }

    cout << "\nGrades:\n";
    for(int i = 0; i < students.size(); i++) {
        students[i]->computeGrade();
    }

    return 0;
}