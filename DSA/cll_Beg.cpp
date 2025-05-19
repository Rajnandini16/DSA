#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;  // Head of the circular linked list
    int choice, value;

    cout << "1. Display\n2. Insert at beginning\n3. Delete at beginning\n4. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) { // Display
            if (head == nullptr) {
                cout << "List is empty\n";
            } else {
                int* temp = head;
                cout << "List: ";
                do {
                    cout << temp[0] << " ";
                    temp = (int*)temp[1];
                } while (temp != head);
                cout << endl;
            }
        }

        else if (choice == 2) { // Insert at beginning
            cout << "Enter value: ";
            cin >> value;
            int* newNode = new int[2];
            newNode[0] = value;

            if (head == nullptr) {
                newNode[1] = (int)newNode;
                head = newNode;
            } else {
                int* temp = head;
                while ((int*)temp[1] != head) {
                    temp = (int*)temp[1];
                }
                temp[1] = (int)newNode;
                newNode[1] = (int)head;
                head = newNode;
            }
        }

        else if (choice == 3) { // Delete at beginning
            if (head == nullptr) {
                cout << "List is empty\n";
            } else if ((int*)head[1] == head) { // only one node
                cout << "Deleted: " << head[0] << endl;
                delete[] head;
                head = nullptr;
            } else {
                int* temp = head;
                while ((int*)temp[1] != head) {
                    temp = (int*)temp[1];
                }
                int* delNode = head;
                head = (int*)head[1];
                temp[1] = (int)head;
                cout << "Deleted: " << delNode[0] << endl;
                delete[] delNode;
            }
        }

        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}