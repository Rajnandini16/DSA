#include <iostream>
using namespace std;

int main() {
    int* top = nullptr;
    int choice, value;

    cout << "Stack Operations:\n1. Push\n2. Pop\n3. Display\n4. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // Push
            cout << "Enter value to push: ";
            cin >> value;
            int* newNode = new int[2];
            newNode[0] = value;
            newNode[1] = (int)(long long)top;  // store pointer as int
            top = newNode;
        } else if (choice == 2) {  // Pop
            if (top == nullptr) {
                cout << "Stack Underflow!\n";
            } else {
                cout << "Popped element: " << top[0] << endl;
                int* temp = top;
                top = (int*)(long long)temp[1];  // convert back to pointer
                delete[] temp;
            }
        } else if (choice == 3) {  // Display
            if (top == nullptr) {
                cout << "Stack is empty!\n";
            } else {
                cout << "Stack elements: ";
                int* temp = top;
                while (temp != nullptr) {
                    cout << temp[0] << " ";
                    temp = (int*)(long long)temp[1];
                }
                cout << endl;
            }
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}