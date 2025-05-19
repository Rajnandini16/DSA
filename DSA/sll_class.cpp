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

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        cout << "Deleted: " << temp->next->data << endl;
        delete temp->next;
        temp->next = nullptr;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\n1. Display\n2. Insert at end\n3. Delete at end\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            list.display();
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            cout << "Inserted at end.\n";
        } else if (choice == 3) {
            list.deleteAtEnd();
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
