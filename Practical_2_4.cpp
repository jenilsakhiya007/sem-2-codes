#include <iostream>
#include <string>
using namespace std;
class Items
{
    int it_id;
    string name;
    float price;
    int stock;

public:
    Items()
    {
        it_id = 0;
        name = "";
        price = 0;
        stock = 0;
    }
    void add();
    void sell();
    void display();
    char search(int id)
    {
        if (id == it_id)
            return 'v';
        return 'i';
    }
};
void Items::add()
{
    cout << "Enter Item ID :";
    cin >> it_id;
    cout << "Enter Item name :";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Item price :";
    cin >> price;
    cout << "Enter Item's Stock :";
    cin >> stock;
}
void Items::sell()
{
    int q;
    cout << "Enter a quantity of item :";
    cin >> q;
    if (q <= stock)
    {
        cout << "Item sold successfully !\n";
        stock -= q;
    }
    else
    {
        cout << "insufficient quantity !\n";
    }
}
void Items::display()
{
    cout << "Item :" << name << endl;
    cout << "ID :" << it_id << endl;
    cout << "Price :" << price << endl;
    cout << "Stock :" << stock << endl;
}
int main()
{
    int choice, index = 0, i;
    Items it[10];

    do
    {
        cout << "\n1.Add the Item\n";
        cout << "2.Sell the Item\n";
        cout << "3.Display the Item\n";
        cout << "4.Exit\n";
        cout << "Enter  your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            it[index].add();
            index++;
            break;

        case 2:
            int id;
            cout << "Enter Item ID :";
            cin >> id;
            for (i = 0; i < index; i++)
            {
                if (it[i].search(id) == 'v')
                {
                    it[i].sell();
                    break;
                }
            }
            if (index == i)
            {
                cout << "Item not found !\n";
            }
            break;

        case 3:
            for (i = 0; i < index; i++)
            {
                it[i].display();
            }
            break;
        case 4:
            cout << "Thank you for visiting...\n";
            return 0;
        default:
            cout << "Invalide choice !\n";
            break;
        }

    } while (choice != 4);
    return 0;
}