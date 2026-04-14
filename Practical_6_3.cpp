#include<iostream>
using namespace std;

class Fuel
{
protected:
    string fuel_type;
public:
    Fuel() { fuel_type = ""; }
    Fuel(string f)
    {
        fuel_type = f;
    }
    void displayFuel()
    {
        cout << "Fuel Type: " << fuel_type << endl;
    }
};

class Brand
{
protected:
    string brand_name;
public:
    Brand() { brand_name = ""; }
    Brand(string b)
    {
        brand_name = b;
    }
    void displayBrand()
    {
        cout << "Brand: " << brand_name << endl;
    }
};

class Car : public Fuel, public Brand
{
private:
    int car_id;
public:
     Car() : Fuel(), Brand()
    {
        car_id = 0;
    }
    Car(int id, string f, string b) : Fuel(f), Brand(b)
    {
        car_id = id;
    }
    void displayCar()
    {
        cout << "Car ID: " << car_id << endl;
        displayFuel();
        displayBrand();
    }
    int getId()
    {
        return car_id;
    }
};

int main()
{
    int n,i;
    cout<<"Enter Cars :";
    cin >> n;

    Car cars[n];

    for(i = 0; i < n; i++)
    {
        int id;
        string fuel, brand;
        cout<<"Enter Car id no :";
        cin >> id;
        cout<<"Enter fuel type :";
        cin>>fuel;
        cout<<"Enter Brand name :";
        cin>>brand;
        
        cars[i] = Car(id, fuel, brand);
    }

    for(i = 0; i < n; i++)
    {
        cars[i].displayCar();
    }

    int search_id;
    cout<<"\nSearch By car id no :";
    cin >> search_id;

    for(i = 0; i < n; i++)
    {
        if(cars[i].getId() == search_id)
        {
            cout<<"car found...\n";
            cars[i].displayCar();
            break;
        }
    }
    if(i==n){
        cout<<"\nCar not found !";
    }

    return 0;
}