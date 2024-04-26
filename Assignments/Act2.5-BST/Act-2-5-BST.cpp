//Mauricio Zavala Sánchez
//A00837332
//ITC
#include <iostream>
#include "BST.h"

using namespace std;



int main() {
    BST<int> bst;
    int choice, data;
    int level; // Declarar la variable fuera del bloque switch

    while (true) {
        cout << "Binary Search Tree Menu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Find" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Inorder Traversal" << endl;
        cout << "6. Postorder Traversal" << endl;
        cout << "7. Level by Level Traversal" << endl;
        cout << "8. Print Tree" << endl;
        cout << "9. Height" << endl;
        cout << "10. Ancestors" << endl;
        cout << "11. What Level Am I?" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                bst.insert(data);
                break;
            case 2:
                cout << "Enter value to find: ";
                cin >> data;
                if (bst.find(data)) {
                    cout << "Value " << data << " found in the tree." << endl;
                } else {
                    cout << "Value " << data << " not found in the tree." << endl;
                }
                break;
            case 3:
                cout << "Enter value to remove: ";
                cin >> data;
                if (bst.remove(data)) {
                    cout << "Value " << data << " removed from the tree." << endl;
                } else {
                    cout << "Value " << data << " not found in the tree. Cannot remove." << endl;
                }
                break;
            case 4:
                cout << "Preorder Traversal: ";
                bst.visit(1);
                break;
            case 5:
                cout << "Inorder Traversal: ";
                bst.visit(2);
                break;
            case 6:
                cout << "Postorder Traversal: ";
                bst.visit(3);
                break;
            case 7:
                cout << "Level by Level Traversal: ";
                bst.visit(4);
                break;
            case 8:
                cout << "Binary Search Tree:" << endl;
                bst.print();
                break;
            case 9:
                cout << "Tree Height: " << bst.height() << endl;
                break;
            case 10:
                cout << "Enter value to find ancestors: ";
                cin >> data;
                cout << "Ancestors of " << data << ": ";
                bst.ancestors(data);
                cout << endl;
                break;
            case 11:
                cout << "Enter value to find its level: ";
                cin >> data;
                level = bst.whatLevelAml(data); // Asignar el valor aquí
                if (level == -1) {
                    cout << "Value " << data << " not found in the tree." << endl;
                } else {
                    cout << "Level of " << data << " is " << level << endl;
                }
                break;
            case 12:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
