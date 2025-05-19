#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\n1. Display\n2. Insert at end\n3. Delete at end\n4. Exit\nEnter choice: ";
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

        } else if (choice == 2) {  // Insert at end
            cout << "Enter value: ";
            cin >> value;
            int* newNode = new int[3]; // [0]=prev, [1]=data, [2]=next
            newNode[0] = 0;
            newNode[1] = value;
            newNode[2] = 0;

            if (head == nullptr) {
                head = newNode;
            } else {
                int* temp = head;
                while ((int*)(long long)temp[2] != nullptr)
                    temp = (int*)(long long)temp[2];
                temp[2] = (int)(long long)newNode;
                newNode[0] = (int)(long long)temp;
            }
            cout << "Inserted at end.\n";

        } else if (choice == 3) {  // Delete at end
            if (head == nullptr) {
                cout << "List is empty\n";
            } else if ((int*)(long long)head[2] == nullptr) {  // Only one node
                cout << "Deleted: " << head[1] << endl;
                delete[] head;
                head = nullptr;
            } else {
                int* temp = head;
                while ((int*)(long long)temp[2] != nullptr)
                    temp = (int*)(long long)temp[2];
                cout << "Deleted: " << temp[1] << endl;
                int* prev = (int*)(long long)temp[0];
                prev[2] = 0;
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