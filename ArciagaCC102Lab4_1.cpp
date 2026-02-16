#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;

    do {
        int students, quizzes;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        float scores[students][quizzes];
        float average[students];

        for (int i = 0; i < students; i++) {
            float sum = 0;
            cout << "\nStudent " << i + 1 << " scores:\n";

            for (int j = 0; j < quizzes; j++) {
                cout << "Quiz " << j + 1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = sum / quizzes;
        }
        cout << "\n------------------------------------------------------------\n";
        cout << "Student\t";

        for (int j = 0; j < quizzes; j++)
            cout << "Q" << j + 1 << "\t";

        cout << "Average\n";
        cout << "------------------------------------------------------------\n";

        for (int i = 0; i < students; i++) {
            cout << i + 1 << "\t";

            for (int j = 0; j < quizzes; j++)
                cout << scores[i][j] << "\t";

            cout << fixed << setprecision(2) << average[i] << endl;
        }

        cout << "------------------------------------------------------------\n";

        cout << "\nRun program again? [Y/y]: ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
