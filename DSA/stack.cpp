#include <iostream>
using namespace std;

int stack[100];  // Fixed-size array for stack
int top = -1;    // Stack pointer

int main() {
    int choice, value, size;

    cout << "Enter stack size: ";
    cin >> size;

    cout << "Stack Operations:\n1. Push\n2. Pop\n3. Display\n4. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (top >= size - 1) {
                cout << "Stack Overflow!\n";
            } else {
                cout << "Enter value to push: ";
                cin >> value;
                stack[++top] = value;
            }
        } else if (choice == 2) {
            if (top < 0) {
                cout << "Stack Underflow!\n";
            } else {
                cout << "Popped element: " << stack[top--] << endl;
            }
        } else if (choice == 3) {
            if (top < 0) {
                cout << "Stack is empty!\n";
            } else {
                cout << "Stack elements: ";
                for (int i = top; i >= 0; i--)
                    cout << stack[i] << " ";
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