#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\n1. Display\n2. Insert at end\n3. Delete at end\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) { // Display
            if (head == nullptr) {
                cout << "List is empty\n";
            } else {
                int* temp = head;
                cout << "List: ";
                while (temp != nullptr) {
                    cout << temp[0] << " ";
                    temp = (int*)(long long)temp[1];
                }
                cout << endl;
            }
        }

        else if (choice == 2) { // Insert at end
            cout << "Enter value: ";
            cin >> value;
            int* newNode = new int[2];
            newNode[0] = value;
            newNode[1] = 0;

            if (head == nullptr) {
                head = newNode;
            } else {
                int* temp = head;
                while ((int*)(long long)temp[1] != nullptr)
                    temp = (int*)(long long)temp[1];
                temp[1] = (int)(long long)newNode;
            }
        }

        else if (choice == 3) { // Delete at end
            if (head == nullptr) {
                cout << "List is empty\n";
            } else if ((int*)(long long)head[1] == nullptr) {
                cout << "Deleted: " << head[0] << endl;
                delete[] head;
                head = nullptr;
            } else {
                int* temp = head;
                while ((int*)(long long)((int*)(long long)temp[1])[1] != nullptr)
                    temp = (int*)(long long)temp[1];
                int* last = (int*)(long long)temp[1];
                cout << "Deleted: " << last[0] << endl;
                delete[] last;
                temp[1] = 0;
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