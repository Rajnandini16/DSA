#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;
    int choice, val;

    while (true) {
        cout << "\n1.Insert at end\n2.Search\n3.Display\n4.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;

            int* newNode = new int[2];
            newNode[0] = val;
            newNode[1] = (int)nullptr;

            if (head == nullptr)
                head = newNode;
            else {
                int* temp = head;
                while ((int*)temp[1] != nullptr)
                    temp = (int*)temp[1];
                temp[1] = (int)newNode;
            }
        }
        else if (choice == 2) {
            if (head == nullptr) {
                cout << "List empty\n";
                continue;
            }
            cout << "Enter value to search: ";
            cin >> val;

            int* temp = head;
            int found = 0;  // 0 = not found, 1 = found
            while (temp != nullptr) {
                if (temp[0] == val) {
                    found = 1;
                    break;
                }
                temp = (int*)temp[1];
            }
            if (found == 1)
                cout << "Found\n";
            else
                cout << "Not found\n";
        }
        else if (choice == 3) {
            int* temp = head;
            cout << "List: ";
            while (temp != nullptr) {
                cout << temp[0] << " ";
                temp = (int*)temp[1];
            }
            cout << "\n";
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid\n";
        }
    }
    return 0;
}