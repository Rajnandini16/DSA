#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;
    int choice, val;

    while (true) {
        cout << "\n1. Create (Insert at end)\n2. Insert sorted\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) { // Insert at end
            cout << "Enter value: ";
            cin >> val;
            int* newNode = new int[2];
            newNode[0] = val;
            newNode[1] = (int)nullptr;

            if (head == nullptr) {
                head = newNode;
            } else {
                int* temp = head;
                while ((int*)temp[1] != nullptr)
                    temp = (int*)temp[1];
                temp[1] = (int)newNode;
            }
        }

        else if (choice == 2) { // Insert in sorted order
            cout << "Enter value: ";
            cin >> val;
            int* newNode = new int[2];
            newNode[0] = val;
            newNode[1] = (int)nullptr;

            if (head == nullptr || val < head[0]) {
                newNode[1] = (int)head;
                head = newNode;
            } else {
                int* temp = head;
                while ((int*)temp[1] != nullptr && ((int*)temp[1])[0] < val)
                    temp = (int*)temp[1];
                newNode[1] = temp[1];
                temp[1] = (int)newNode;
            }
        }

        else if (choice == 3) { // Display
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