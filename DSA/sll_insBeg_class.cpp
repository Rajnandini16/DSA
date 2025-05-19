#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted at beginning.\n";
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        cout << "Deleted: " << temp->data << endl;
        head = head->next;
        delete temp;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        cout << "List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\n1. Display\n2. Insert at beginning\n3. Delete at beginning\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.display();
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 3:
                list.deleteAtBeginning();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
