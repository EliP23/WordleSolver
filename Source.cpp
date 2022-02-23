#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int currentLineindex = 0;
string dictionary[5746];

int main() {
    string line;
    ifstream myfile("Wordlist.txt");

    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, line);
            dictionary[currentLineindex] = line;
            currentLineindex++;
        }
        myfile.close();
    }

    string word;
    cout << "Enter * for unknown letters, enter '<character>' for known letters ---> " << endl;
    cin >> word;


    int foundIndexs[5000];
    int foundIndexCoutner = 0;

    for (int i = 0; i < size(dictionary); i++) {
        if (dictionary[i].at(0) == word.at(0) || (word.at(0) == '*')){
            if ((dictionary[i].at(1) == word.at(1)) || (word.at(1) == '*')) {
                if ((dictionary[i].at(2) == word.at(2)) || (word.at(2) == '*')) {
                    if ((dictionary[i].at(3) == word.at(3)) || (word.at(3) == '*')) {
                        if ((dictionary[i].at(4) == word.at(4)) || (word.at(4) == '*')) {
                            foundIndexs[foundIndexCoutner] = i;
                            foundIndexCoutner++; 
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < size(foundIndexs); i++) {
        if (foundIndexs[i] != -858993460) {
            cout << dictionary[foundIndexs[i]] << " ";
        }   
    }
}