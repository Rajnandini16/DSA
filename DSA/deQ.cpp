#include <iostream>
using namespace std;

int deque[100];  // Fixed-size array for deque
int front = -1, rear = -1, dequeSize;

int main() {
    int choice, value;

    cout << "Enter deque size (max 100): ";
    cin >> dequeSize;

    cout << "Deque Operations:\n1. Insert at Beginning\n2. Insert at End\n3. Delete at Beginning\n4. Delete at End\n5. Display\n6. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // Insert at Beginning
            if ((rear + 1) % dequeSize == front) {
                cout << "Deque Overflow!\n";
            } else {
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                if (front == -1) {
                    front = rear = 0;
                } else {
                    front = (front - 1 + dequeSize) % dequeSize;
                }
                deque[front] = value;
            }
        } else if (choice == 2) {  // Insert at End
            if ((rear + 1) % dequeSize == front) {
                cout << "Deque Overflow!\n";
            } else {
                cout << "Enter value to insert at end: ";
                cin >> value;
                if (rear == -1) {
                    front = rear = 0;
                } else {
                    rear = (rear + 1) % dequeSize;
                }
                deque[rear] = value;
            }
        } else if (choice == 3) {  // Delete at Beginning
            if (front == -1) {
                cout << "Deque Underflow!\n";
            } else {
                cout << "Deleted element from beginning: " << deque[front] << endl;
                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % dequeSize;
                }
            }
        } else if (choice == 4) {  // Delete at End
            if (rear == -1) {
                cout << "Deque Underflow!\n";
            } else {
                cout << "Deleted element from end: " << deque[rear] << endl;
                if (front == rear) {
                    front = rear = -1;
                } else {
                    rear = (rear - 1 + dequeSize) % dequeSize;
                }
            }
        } else if (choice == 5) {  // Display
            if (front == -1) {
                cout << "Deque is empty!\n";
            } else {
                cout << "Deque elements: ";
                int i = front;
                while (true) {
                    cout << deque[i] << " ";
                    if (i == rear) break;
                    i = (i + 1) % dequeSize;
                }
                cout << endl;
            }
        } else if (choice == 6) {  // Exit
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

return 0;
}