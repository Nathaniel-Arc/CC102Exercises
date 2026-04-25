#include <iostream>
#include <fstream>

using namespace std;

// Simple check to see if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false; // Found a factor, so it's not prime
        }
    }
    return true;
}

int main() {
    ifstream inputFile("NUMS.TXT");
    int number;
    int count = 0;

    // Check if the file actually opened
    if (!inputFile) {
        cout << "File not found!" << endl;
        return 1;
    }

    // Read the file number by number
    while (inputFile >> number) {
        if (isPrime(number)) {
            count++;
        }
    }

    cout << "Total prime numbers: " << count << endl;

    inputFile.close();
    return 0;
}
