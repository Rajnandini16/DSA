#include <iostream>
using namespace std;

int main() {
    int* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\n1. Display\n2. Sort list\n3. Count nodes\n4. Insert (append)\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {  // Display
            if (head == nullptr) {
                cout << "List is empty\n";
            } else {
                cout << "List: ";
                int* temp = head;
                while (temp != nullptr) {
                    cout << temp[0] << " ";
                    temp = (int*)(long long)temp[1];
                }
                cout << endl;
            }

        } else if (choice == 2) {  // Sort elements (bubble sort)
            if (head == nullptr || (int*)(long long)head[1] == nullptr) {
                cout << "List too small to sort\n";
            } else {
                bool swapped;
                do {
                    swapped = false;
                    int* ptr1 = head;
                    int* ptr2 = (int*)(long long)ptr1[1];

                    while (ptr2 != nullptr) {
                        if (ptr1[0] > ptr2[0]) {
                            int temp = ptr1[0];
                            ptr1[0] = ptr2[0];
                            ptr2[0] = temp;
                            swapped = true;
                        }
                        ptr1 = ptr2;
                        ptr2 = (int*)(long long)ptr2[1];
                    }
                } while (swapped);
                cout << "List sorted\n";
            }

        } else if (choice == 3) {  // Count nodes
            int count = 0;
            int* temp = head;
            while (temp != nullptr) {
                count++;
                temp = (int*)(long long)temp[1];
            }
            cout << "Total nodes: " << count << endl;

        } else if (choice == 4) {  // Insert at end
            cout << "Enter value to insert: ";
            cin >> value;
            int* newNode = new int[2];
            newNode[0] = value;
            newNode[1] = 0;

            if (head == nullptr) {
                head = newNode;
            } else {
                int* temp = head;
                while ((int*)(long long)temp[1] != nullptr)
                    temp = (int*)(long long)temp[1];
                temp[1] = (int)(long long)newNode;
            }

        } else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}