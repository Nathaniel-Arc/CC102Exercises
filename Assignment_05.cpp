#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream outFile("original.txt");

    if (outFile.is_open()) {
        outFile << "One" << endl;
        outFile << "Two" << endl;
        outFile << "Three" << endl;
        outFile << "Four" << endl;
        outFile << "Five" << endl;
        outFile << "Six" << endl;
        outFile.close();
    } else {
        cout << "Error opening original.txt" << endl;
        return 1;
    }

    ifstream inFile("original.txt");
    vector<string> lines;
    string line;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            lines.push_back(line);
        }
        inFile.close();
    } else {
        cout << "Error opening original.txt for reading" << endl;
        return 1;
    }

    sort(lines.begin(), lines.end());

    ofstream sortedFile("sorted.txt");

    if (sortedFile.is_open()) {
        for (const string& s : lines) {
            sortedFile << s << endl;
        }
        sortedFile.close();
        cout << "Files processed and sorted successfully!" << endl;
    } else {
        cout << "Error opening sorted.txt" << endl;
        return 1;
    }

    return 0;
}
