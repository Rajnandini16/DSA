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

    void insertEnd(int val) {
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

    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sortList() {
        if (head == nullptr || head->next == nullptr) {
            cout << "List too small to sort\n";
            return;
        }
        bool swapped;
        do {
            swapped = false;
            Node* curr = head;
            while (curr->next != nullptr) {
                if (curr->data > curr->next->data) {
                    swap(curr->data, curr->next->data);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
        cout << "List sorted\n";
    }

    void countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total nodes: " << count << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\n1. Display\n2. Sort list\n3. Count nodes\n4. Insert (append)\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.display();
                break;
            case 2:
                list.sortList();
                break;
            case 3:
                list.countNodes();
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
