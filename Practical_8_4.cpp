#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string filename;
    ifstream file;

    while(true) {
        cout << "Enter file path: ";
        cin >> filename;
        file.open(filename);

        if(file.is_open())
            break;
        else {
            cout << "File not found. Try again\n";
            file.clear();
        }
    }

    string line;
    int lineNo = 0;

    while(getline(file, line)) {
        lineNo++;
        stringstream ss(line);
        double num, sum = 0;
        bool valid = true;

        while(ss >> num) {
            sum += num;
        }

        if(ss.fail() && !ss.eof())
            valid = false;

        if(valid)
            cout << "Line " << lineNo << " Sum: " << sum << endl;
        else
            cout << "Line " << lineNo << " contains invalid data\n";
    }

    file.close();
    return 0;
}