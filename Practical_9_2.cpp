#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    map<string, int> freq;
    stringstream ss(sentence);
    string word;

    while(ss >> word) {
        freq[word]++;
    }

    cout << "\nWord Frequencies:\n";
    for(auto it = freq.begin(); it != freq.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}