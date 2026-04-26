#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<string, vector<string>> dir;
    int choice;

    while(choice!=4) {
        cout << "\n1. Add Folder\n2. Add File\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string folder;
                cout << "Enter folder name: ";
                cin >> folder;
                dir[folder];
                break;
            }
            case 2: {
                string folder, file;
                cout << "Enter folder name: ";
                cin >> folder;
                if(dir.find(folder) == dir.end()) {
                    cout << "Folder not found\n";
                } else {
                    cout << "Enter file name: ";
                    cin >> file;
                    dir[folder].push_back(file);
                }
                break;
            }
            case 3: {
                cout << "\nDirectory:\n";
                for(auto it = dir.begin(); it != dir.end(); it++) {
                    cout << it->first << ":\n";
                    for(auto f : it->second) {
                        cout << "  " << f << endl;
                    }
                }
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}