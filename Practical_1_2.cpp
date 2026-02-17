#include <iostream>
#include <string>
using namespace std;

class Library
{
private:
    int book_id;
    string author;
    string title;
    int copies;

public:
    void addBook();
    bool searchBook(string);
    void issueBook();
    void returnBook();
    void displayBook();
};


void Library::addBook()
{
    cout << "Enter Book ID: ";
    cin >> book_id;
    cin.ignore();

    cout << "Enter Author Name: ";
    getline(cin, author);

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Number of Copies: ";
    cin >> copies;
}

bool Library::searchBook(string t)
{
    return title == t;
}

void Library::issueBook()
{
    if (copies > 0)
    {
        copies--;
        cout << "Book issued successfully.\n";
    }
    else
    {
        cout << "No copies available.\n";
    }
}

void Library::returnBook()
{
    copies++;
    cout << "Book returned successfully.\n";
}

void Library::displayBook()
{
    cout <<"\nBook ID   : " << book_id;
    cout <<"\nTitle     : " << title;
    cout <<"\nAuthor    : " << author;
    cout <<"\nCopies    : " << copies << "\n";
}

int main()
{
    Library b[10];
    int count = 0;
    int choice,i;

    while (true)
    {     
        L:
        cout << "\n1. Add Book";
        cout << "\n2. Issue Book";
        cout << "\n3. Return Book";
        cout << "\n4. Display Books";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            b[count].addBook();
            count++;
            break;

        case 2:
        {
            string t;
            if (count==0){
                cout<<"First add books\n";
                goto L;
            }
            else{
            cout << "Enter Book Title: ";
            getline(cin, t);

            
            for (i = 0; i < count; i++)
            {
                if (b[i].searchBook(t))
                {
                    b[i].issueBook();
                    break;
                }
            }
            if (i==count)
                cout << "Book not found.\n";
            break;
        }
        }

        case 3:
        {
            string t;
            cout << "Enter Book Title: ";
            getline(cin, t);

            for (i = 0; i < count; i++)
            {
                if (b[i].searchBook(t))
                {
                    b[i].returnBook();
                    break;
                }
            }
            if (i==count)
                cout << "Book not found.\n";
            break;
        }

        case 4:
            for (i = 0; i < count; i++)
                b[i].displayBook();
            break;

        case 5:
            cout<<"Thank you for visiting.....";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
