#include <iostream>
#include <string>

using namespace std;

struct book {
    string barcode;
    string title;
    int year;
    int rating;
};

int main() {
  char repeat = 'y';
    do {
      int n;
      cout << "Enter the number of books: ";
      cin >> n;

      book library[100];
  
      for (int i = 0; i < n; i++) {
          cout << "\nBook #" << i + 1 << endl;
  
        for (int isUnique = 0; isUnique == 0; ) {
          cout << "Barcode: ";
          cin >> library[i].barcode;
  
            int found = 0;
            for (int j = 0; j < i; j++) {
              if (library[i].barcode == library[j].barcode) {
                found = 1;
                }
            }
            if (found == 1) {
              cout << "Error: Barcode already exists. Try again.\n";
            } else {
              isUnique = 1;
            }
        }
          cout << "Title: ";
          cin.ignore();
          getline(cin, library[i].title);
          cout << "Year Published: ";
          cin >> library[i].year;
          cout << "Rating (0-5): ";
          cin >> library[i].rating;
      }
      cout << "\nBarcode\tTitle\tYear\tRating\tCategory\n";
      cout << "--------------------------------------------------\n";
  
      for (int i = 0; i < n; i++) {
          string category;
          if (library[i].rating == 5) category = "Excellent";
          else if (library[i].rating == 4) category = "Very Good";
          else if (library[i].rating == 3) category = "Good";
          else if (library[i].rating == 2) category = "Fair";
          else if (library[i].rating == 1) category = "Poor";
          else category = "No Rating";
  
          cout << library[i].barcode << "\t"
               << library[i].title << "\t"
               << library[i].year << "\t"
               << library[i].rating << "\t"
               << category << endl;
      }
      cout << "\nRepeat? [Y/y]: ";
      cin >> repeat;
  } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
