#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to display the linked list
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

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
    cout << "Inserted at beginning.\n";
}

// Function to delete a node from the beginning
void deleteAtBeginning(Node*& head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    cout << "Deleted: " << temp->data << endl;
    head = head->next;
    delete temp;
}

// Main function with menu-driven interface
int main() {
    Node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\n1. Display\n2. Insert at beginning\n3. Delete at beginning\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 3:
                deleteAtBeginning(head);
                break;
            case 4:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
