#include <iostream>

using namespace std;

class Calculator
{
    private:
    float results[10];
    int index = 0;

    public:

    int add(int a, int b)
    {
        int res = a + b;
        results[index++] = res;
        cout << a << " + " << b << " = " << res << endl;
        return res;
    }

    float add(float a, float b)
    {
        float res = a + b;
        results[index++] = res;
        cout << a << " + " << b << " = " << res << endl;
        return res;
    }

    float add(int a, float b)
    {
        float res = a + b;
        results[index++] = res;
        cout << a << " + " << b << " = " << res << endl;
        return res;
    }

    float add(float a, int b)
    {
        float res = a + b;
        results[index++] = res;
        cout << a << " + " << b << " = " << res << endl;
        return res;
    }

    void displayAllResults()
    {
        cout << "\nStored Results:\n";
        for(int i = 0; i < index; i++)
        {
            cout << results[i] << endl;
        }
    }
};

int main()
{
    Calculator calc;

    calc.add(10, 10);
    calc.add(5.5f, 2.5f);
    calc.add(10, 2.5f);
    calc.add(3.5f, 4);

    calc.displayAllResults();

    return 0;
}