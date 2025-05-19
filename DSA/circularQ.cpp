#include <iostream>
using namespace std;

int queue[100];  // Fixed-size array for queue
int front = -1, rear = -1, queueSize;

int main() {
    int choice, value;

    cout << "Enter queue size (max 100): ";
    cin >> queueSize;

    cout << "Circular Queue Operations:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) { // Enqueue
            if ((rear + 1) % queueSize == front) {
                cout << "Queue Overflow!\n";
            } else {
                cout << "Enter value to enqueue: ";
                cin >> value;
                if (front == -1) front = 0;
                rear = (rear + 1) % queueSize;
                queue[rear] = value;
            }
        } else if (choice == 2) { // Dequeue
            if (front == -1) {
                cout << "Queue Underflow!\n";
            } else {
                cout << "Dequeued element: " << queue[front] << endl;
                if (front == rear) {
                    front = rear = -1;  // Reset queue when empty
                } else {
                    front = (front + 1) % queueSize;
                }
            }
        } else if (choice == 3) { // Display
            if (front == -1) {
                cout << "Queue is empty!\n";
            } else {
                cout << "Queue elements: ";
                int i = front;
                while (true) {
                    cout << queue[i] << " ";
                    if (i == rear) break;
                    i = (i + 1) % queueSize;
                }
                cout << endl;
            }
        } else if (choice == 4) { // Exit
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}