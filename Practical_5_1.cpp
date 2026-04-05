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

    string word;
    string words[100];
    int count[100];
    int size = 0;

    while(file >> word) {

        for(int i = 0; i < word.length(); i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                word[i] = word[i] + 32;
            }
        }

        int found = 0;

        for(int i = 0; i < size; i++) {
            if(words[i] == word) {
                count[i]++;
                found = 1;
                break;
            }
        }

        if(found == 0) {
            words[size] = word;
            count[size] = 1;
            size++;
        }
    }

    file.close();

    for(int i = 0; i < size; i++) {
        cout<<words[i]<<" : "<<count[i]<<endl;
    }

    return 0;
}