#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;
    int choice, val;

    while (true) {
        cout << "\n1. Insert at end\n2. Delete given value\n3. Display\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Value: ";
            cin >> val;
            int* newNode = new int[2];
            newNode[0] = val;
            newNode[1] = (int)nullptr;

            if (head == nullptr) head = newNode;
            else {
                int* temp = head;
                while ((int*)temp[1] != nullptr)
                    temp = (int*)temp[1];
                temp[1] = (int)newNode;
            }
        }
        else if (choice == 2) {
            cout << "Delete value: ";
            cin >> val;
            if (head == nullptr) {
                cout << "Empty list\n";
                continue;
            }
            if (head[0] == val) {
                int* temp = head;
                head = (int*)head[1];
                delete[] temp;
                cout << "Deleted\n";
            } else {
                int* temp = head;
                while ((int*)temp[1] != nullptr && ((int*)temp[1])[0] != val)
                    temp = (int*)temp[1];
                if ((int*)temp[1] == nullptr) cout << "Not found\n";
                else {
                    int* del = (int*)temp[1];
                    temp[1] = del[1];
                    delete[] del;
                    cout << "Deleted\n";
                }
            }
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
        else if (choice == 4) break;
        else cout << "Invalid\n";
    }
    return 0;
}