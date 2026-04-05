#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream file;
    file.open("input.txt");

    if(!file) {
        cout<<"File not found";
        return 0;
    }

    string line;
    int lines = 0, words = 0, chars = 0;

    while(getline(file, line)) {
        lines++;

        for(int i = 0; i < line.length(); i++) {
            if(line[i]==' '){
            goto L;
            }
            else chars++;
            L:
            if((i == 0 && line[i] != ' ') || 
               (i > 0 && line[i] != ' ' && line[i-1] == ' ')) {
                words++;
            }
        }
    }

    file.close();

    cout<<"Lines: "<<lines<<endl;
    cout<<"Words: "<<words<<endl;
    cout<<"Characters: "<<chars<<endl;

    return 0;
}