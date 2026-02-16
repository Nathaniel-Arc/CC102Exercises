#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;

    do {
        const int PRODUCTS = 5;
        const int SALESPERSONS = 4;

        double sales[PRODUCTS][SALESPERSONS] = {0};
        int salesperson, product;
        double amount;
        char more;

        do {
            cout << "\nEnter Salesperson number (1-4): ";
            cin >> salesperson;

            cout << "Enter Product number (1-5): ";
            cin >> product;

            cout << "Enter Amount: ";
            cin >> amount;

            if (salesperson >= 1 && salesperson <= 4 &&
                product >= 1 && product <= 5) {
                sales[product - 1][salesperson - 1] += amount;
            } else {
                cout << "Invalid input!\n";
            }

            cout << "Enter another sale? (y/n): ";
            cin >> more;

        } while (more == 'y' || more == 'Y');

        cout << "\n\nSalesperson\n";
        cout << setw(10) << "Product";

        for (int s = 0; s < SALESPERSONS; s++) {
            cout << setw(10) << s + 1;
        }
        cout << setw(10) << "Total\n";

        double grandTotal = 0;

        for (int i = 0; i < PRODUCTS; i++) {
            double rowTotal = 0;
            cout << setw(10) << i + 1;

            for (int j = 0; j < SALESPERSONS; j++) {
                cout << setw(10) << fixed << setprecision(2) << sales[i][j];
                rowTotal += sales[i][j];
            }

            cout << setw(10) << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << setw(10) << "Total";
        for (int j = 0; j < SALESPERSONS; j++) {
            double colTotal = 0;
            for (int i = 0; i < PRODUCTS; i++) {
                colTotal += sales[i][j];
            }
            cout << setw(10) << colTotal;
        }

        cout << setw(10) << grandTotal << endl;

        cout << "\nRun program again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
