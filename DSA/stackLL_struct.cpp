#include <iostream>
using namespace std;

// A structure to represent each node in the stack
struct Node {
    int data;       // value to store
    Node* next;     // pointer to the next node
};

int main() {
    Node* top = nullptr;  // top of the stack
    int choice, value;

    cout << "Stack Operations:\n1. Push (Add)\n2. Pop (Remove)\n3. Display (Show)\n4. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  // Push
            cout << "Enter value to push: ";
            cin >> value;
            Node* newNode = new Node;  // create a new node
            newNode->data = value;     // store value in the node
            newNode->next = top;       // link to previous top
            top = newNode;             // update top to the new node
        } 
        else if (choice == 2) {  // Pop
            if (top == nullptr) {
                cout << "Stack is empty! Nothing to pop.\n";
            } else {
                cout << "Popped: " << top->data << endl;
                Node* temp = top;      // hold current top
                top = top->next;       // move top to next node
                delete temp;           // free memory of popped node
            }
        } 
        else if (choice == 3) {  // Display
            if (top == nullptr) {
                cout << "Stack is empty!\n";
            } else {
                cout << "Stack: ";
                Node* temp = top;
                while (temp != nullptr) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        } 
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
