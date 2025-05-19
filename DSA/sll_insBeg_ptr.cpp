#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\n1. Display\n2. Insert at beginning\n3. Delete at beginning\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {  // Display
            if (head == nullptr) {
                cout << "List is empty\n";
            } else {
                cout << "List: ";
                int* temp = head;
                while (temp != nullptr) {
                    cout << temp[0] << " ";
                    temp = (int*)(long long)temp[1];
                }
                cout << endl;
            }

        } else if (choice == 2) {  // Insert at beginning
            cout << "Enter value: ";
            cin >> value;
            int* newNode = new int[2];
            newNode[0] = value;
            newNode[1] = (int)(long long)head;
            head = newNode;
            cout << "Inserted at beginning.\n";

        } else if (choice == 3) {  // Delete at beginning
            if (head == nullptr) {
                cout << "List is empty\n";
            } else {
                int* temp = head;
                cout << "Deleted: " << temp[0] << endl;
                head = (int*)(long long)temp[1];
                delete[] temp;
            }

        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}