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
                int* temp = head;
                cout << "List: ";
                while (temp != nullptr) {
                    cout << temp[1] << " ";
                    temp = (int*)(long long)temp[2];
                }
                cout << endl;
            }

        } else if (choice == 2) {  // Insert at beginning
            cout << "Enter value: ";
            cin >> value;
            int* newNode = new int[3]; // [0]=prev, [1]=data, [2]=next
            newNode[0] = 0;
            newNode[1] = value;
            newNode[2] = (int)(long long)head;

            if (head != nullptr) {
                head[0] = (int)(long long)newNode;
            }
            head = newNode;
            cout << "Inserted at beginning.\n";

        } else if (choice == 3) {  // Delete at beginning
            if (head == nullptr) {
                cout << "List is empty\n";
            } else {
                cout << "Deleted: " << head[1] << endl;
                int* temp = head;
                head = (int*)(long long)temp[2];
                if (head != nullptr)
                    head[0] = 0;
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