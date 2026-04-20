#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("color.txt");

    if (outFile.is_open()) {
        outFile << "Red" << endl;
        outFile << "Blue" << endl;
        outFile << "Green" << endl;
        outFile << "Yellow" << endl;
        outFile << "Purple" << endl;
        
        outFile.close();
        cout << "File 'color.txt' created successfully." << endl;
    } else {
        cout << "Error: Could not create the source file." << endl;
        return 1; 
    }

    ifstream inFile("color.txt");
    ofstream copyFile("color_copy.txt");

    if (inFile.is_open() && copyFile.is_open()) {
        string line;
        
        while (getline(inFile, line)) {
            copyFile << line << endl;
        }

        inFile.close();
        copyFile.close();
        
        cout << "Copy completed!" << endl;
    } else {
        cout << "Error: Could not open files for copying." << endl;
        return 1;
    }

    return 0;
}
