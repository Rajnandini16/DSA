#include <iostream>
using namespace std;

int main() {
    int *front = nullptr, *rear = nullptr;
    int choice, value;

    cout << "Queue Operations:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // Enqueue
            cout << "Enter value to enqueue: ";
            cin >> value;
            int *newNode = new int[2]; // [0]=data, [1]=next pointer
            newNode[0] = value;
            newNode[1] = 0; // NULL as int

            if (rear == nullptr) {
                front = rear = newNode;
            } else {
                rear[1] = (int)(long long)newNode;
                rear = newNode;
            }
        } else if (choice == 2) {  // Dequeue
            if (front == nullptr) {
                cout << "Queue Underflow!\n";
            } else {
                cout << "Dequeued element: " << front[0] << endl;
                int *temp = front;
                front = (int*)(long long)front[1];
                delete[] temp;
                if (front == nullptr) rear = nullptr;
            }
        } else if (choice == 3) {  // Display
            if (front == nullptr) {
                cout << "Queue is empty!\n";
            } else {
                cout << "Queue elements: ";
                int *temp = front;
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