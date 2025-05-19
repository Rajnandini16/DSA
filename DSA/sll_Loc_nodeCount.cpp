#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert at a specific position
void insertAtPosition(Node*& head, int pos, int val) {
    Node* newNode = new Node{val, nullptr};

    if (pos <= 1 || head == nullptr) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        int count = 1;
        while (temp->next && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Inserted " << val << " at position " << pos << ".\n";
}

// Function to display the list
void display(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    cout << "List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to count the number of nodes
void countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    cout << "Total nodes: " << count << endl;
}

int main() {
    Node* head = nullptr;
    int choice, value, pos;

    while (true) {
        cout << "\n1. Display\n2. Insert at position\n3. Count nodes\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                cout << "Enter position (starting from 1): ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                insertAtPosition(head, pos, value);
                break;
            case 3:
                countNodes(head);
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
