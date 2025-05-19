#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyList {
    Node* head;

public:
    DoublyList() {
        head = nullptr;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted.\n";
    }

    void deleteEnd() {
        if (!head)
            cout << "List is empty\n";
        else if (!head->next) {
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            cout << "Deleted: " << temp->data << endl;
            temp->prev->next = nullptr;
            delete temp;
        }
    }

    void display() {
        if (!head) {
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
    DoublyList list;
    int choice, val;

    while (true) {
        cout << "\n1. Display\n2. Insert at end\n3. Delete at end\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) list.display();
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            list.insertEnd(val);
        } else if (choice == 3) list.deleteEnd();
        else if (choice == 4) break;
        else cout << "Invalid choice\n";
    }

    return 0;
}
