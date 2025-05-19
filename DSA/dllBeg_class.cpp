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
        Node* temp = head;
        cout << "List: ";
        while (temp) {
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

        if (choice == 1)
            list.display();
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
        } else if (choice == 3)
            list.deleteAtBeginning();
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else
            cout << "Invalid choice\n";
    }

    return 0;
}
