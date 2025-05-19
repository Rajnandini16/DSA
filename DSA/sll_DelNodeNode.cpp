#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;
    int choice, val, afterVal;

    while (true) {
        cout << "\n1. Insert at end\n2. Delete node after given value\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            int* newNode = new int[2];
            newNode[0] = val;        // data
            newNode[1] = (int)nullptr; // next pointer

            if (head == nullptr) {
                head = newNode;
            } else {
                int* temp = head;
                while ((int*)temp[1] != nullptr)
                    temp = (int*)temp[1];
                temp[1] = (int)newNode;
            }
        } 
        else if (choice == 2) {
            cout << "Enter value after which to delete node: ";
            cin >> afterVal;

            int* temp = head;
            while (temp != nullptr && temp[0] != afterVal)
                temp = (int*)temp[1];

            if (temp == nullptr) cout << "Value not found.\n";
            else if ((int*)temp[1] == nullptr) cout << "No node after given value.\n";
            else {
                int* delNode = (int*)temp[1];
                temp[1] = delNode[1];
                delete[] delNode;
                cout << "Deleted node after " << afterVal << endl;
            }
        } 
        else if (choice == 3) {
            int* temp = head;
            cout << "List: ";
            while (temp != nullptr) {
                cout << temp[0] << " ";
                temp = (int*)temp[1];
            }
            cout << endl;
        } 
        else if (choice == 4) {
            break;
        } 
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}