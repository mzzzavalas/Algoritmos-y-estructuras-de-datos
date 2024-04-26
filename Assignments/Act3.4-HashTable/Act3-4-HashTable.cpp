//Mauricio Zavala Sánchez
//A00837332
//IRS
#include <iostream>
#include <vector>
using namespace std;

#include "HashStudentId.h"
int main() {
    HashStudentId hashTable;
    int choice;
    string studentId;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Insert student ID\n";
        cout << "2. Remove student ID\n";
        cout << "3. Find student ID\n";
        cout << "4. Print hash table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter student ID: ";
                cin >> studentId;
                hashTable.insert(studentId);
                break;
            case 2:
                cout << "Enter student ID: ";
                cin >> studentId;
                hashTable.remove(studentId);
                break;
            case 3:
                cout << "Enter student ID: ";
                cin >> studentId;
                cout << "Student ID found at index: " << hashTable.findStudentId(studentId) << "\n";
                break;
            case 4:
                hashTable.print();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}