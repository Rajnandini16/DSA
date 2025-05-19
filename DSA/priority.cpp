#include <iostream>
using namespace std;

int arr[100], priority[100], queueSize = 0;  // Renamed 'size' to 'queueSize'

int main() {
    int choice, value, prio;

    cout << "Priority Queue Operations:\n1. Insert\n2. Remove\n3. Display\n4. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // Insert
            if (queueSize >= 100) {
                cout << "Queue Overflow!\n";
            } else {
                cout << "Enter value and priority: ";
                cin >> value >> prio;
                int i;
                for (i = queueSize - 1; i >= 0 && priority[i] > prio; i--) {
                    arr[i + 1] = arr[i];
                    priority[i + 1] = priority[i];
                }
                arr[i + 1] = value;
                priority[i + 1] = prio;
                queueSize++;
            }
        } else if (choice == 2) {  // Remove
            if (queueSize == 0) {
                cout << "Queue Underflow!\n";
            } else {
                cout << "Removed element: " << arr[0] << " (Priority: " << priority[0] << ")\n";
                for (int i = 0; i < queueSize - 1; i++) {
                    arr[i] = arr[i + 1];
                    priority[i] = priority[i + 1];
                }
                queueSize--;
            }
        } else if (choice == 3) {  // Display
            if (queueSize == 0) {
                cout << "Queue is empty!\n";
            } else {
                cout << "Priority Queue:\n";
                for (int i = 0; i < queueSize; i++)
                    cout << arr[i] << " (Priority: " << priority[i] << ")\n";
            }
        } else if (choice == 4) {  // Exit
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}