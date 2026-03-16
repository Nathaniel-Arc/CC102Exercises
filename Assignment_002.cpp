#include <iostream>

using namespace std;

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of subjects: ";
    cin >> subjects;

    int grades[students][subjects];
    int highest = 0;

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << "Enter " << subjects << " grades for Student " << i + 1 << ": ";
            cin >> grades[i][j];
        }
    }
    cout << "\n---Grades Matrix---\n";
    cout << endl;
    int* ptr = (int*)grades;

    for (int i = 0; i < students; i++) {
        float sum = 0;
        cout << "Student " << i + 1 << ": ";

        for (int j = 0; j < subjects; j++) {
            int currentGrade = *(ptr + (i * subjects) + j);
            cout << currentGrade << "\t";

            sum += currentGrade;
            if (currentGrade > highest) highest = currentGrade;
        }

        cout << "| Average: " << (sum / subjects) << endl;
    }
    cout << "\nHighest Grade in Matrix: " << highest << endl;

    return 0;
}
