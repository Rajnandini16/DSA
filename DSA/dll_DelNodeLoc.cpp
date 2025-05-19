#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;
    int choice, val, pos;

    cout << "1. Create (Insert at end)\n2. Delete by position\n3. Display\n4. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) { // Insert at end
            cout << "Enter value: ";
            cin >> val;
            int* node = new int[3]; // [data, prev, next]
            node[0] = val;
            node[1] = (int)nullptr;
            node[2] = (int)nullptr;

            if (head == nullptr) {
                head = node;
            } else {
                int* temp = head;
                while ((int*)temp[2] != nullptr)
                    temp = (int*)temp[2];
                temp[2] = (int)node;
                node[1] = (int)temp;
            }
        }

        else if (choice == 2) { // Delete by position
            cout << "Enter position: ";
            cin >> pos;
            if (pos <= 0 || head == nullptr) {
                cout << "Invalid position\n";
                continue;
            }

            int* temp = head;
            int count = 1;
            while (temp != nullptr && count < pos) {
                temp = (int*)temp[2];
                count++;
            }

            if (temp == nullptr) {
                cout << "Position out of range\n";
            } else {
                if ((int*)temp[1] != nullptr)
                    ((int**)(temp[1]))[0][2] = temp[2];
                else
                    head = (int*)temp[2];
                if ((int*)temp[2] != nullptr)
                    ((int**)(temp[2]))[0][1] = temp[1];
                delete[] temp;
                cout << "Node deleted\n";
            }
        }

        else if (choice == 3) { // Display
            int* temp = head;
            cout << "List: ";
            while (temp != nullptr) {
                cout << temp[0] << " ";
                temp = (int*)temp[2];
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