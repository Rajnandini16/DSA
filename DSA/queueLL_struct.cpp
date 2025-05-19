#include <iostream>
using namespace std;

struct Node {
    int data;      // value stored in the node
    Node* next;    // pointer to the next node in queue
};

int main() {
    Node* front = nullptr;   // points to the front of the queue
    Node* rear = nullptr;    // points to the rear of the queue
    int choice, value;

    cout << "Queue Operations:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // Enqueue
            cout << "Enter value to enqueue: ";
            cin >> value;

            Node* newNode = new Node;  // create new node
            newNode->data = value;
            newNode->next = nullptr;

            if (rear == nullptr) {     // if queue is empty
                front = rear = newNode;  // front and rear are same
            } else {
                rear->next = newNode;    // link new node at the end
                rear = newNode;          // update rear pointer
            }
        } 
        else if (choice == 2) {  // Dequeue
            if (front == nullptr) {
                cout << "Queue Underflow!\n";
            } else {
                cout << "Dequeued element: " << front->data << endl;
                Node* temp = front;
                front = front->next;   // move front forward
                delete temp;           // free old front node

                if (front == nullptr)  // if queue became empty
                    rear = nullptr;
            }
        } 
        else if (choice == 3) {  // Display
            if (front == nullptr) {
                cout << "Queue is empty!\n";
            } else {
                cout << "Queue elements: ";
                Node* temp = front;
                while (temp != nullptr) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        } 
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } 
        else {
            cout << "Invalid choice!\n";
        }
    }

    // Clean up any remaining nodes in case of exit without empty queue
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    return 0;
}
