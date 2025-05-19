#include <iostream>
using namespace std;

int main() {
    int table[10], i;
    for (i = 0; i < 10; i++) table[i] = -1;

    int choice, key, index;

    cout << "1. Insert\n2. Search\n3. Display\n4. Exit\n";

    while (1) {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number to insert: ";
            cin >> key;
            index = key % 10;
            for (i = 0; i < 10; i++) {
                int pos = (index + i) % 10;
                if (table[pos] == -1) {
                    table[pos] = key;
                    break;
                }
            }
            if (i == 10) cout << "Table full\n";
        }

        else if (choice == 2) {
            cout << "Enter number to search: ";
            cin >> key;
            index = key % 10;
            for (i = 0; i < 10; i++) {
                int pos = (index + i) % 10;
                if (table[pos] == key) {
                    cout << "Found at index " << pos << "\n";
                    break;
                }
                if (table[pos] == -1) break;
            }
            if (i == 10 || table[(index + i) % 10] != key)
                cout << "Not found\n";
        }

        else if (choice == 3) {
            cout << "Hash table:\n";
            for (i = 0; i < 10; i++)
                cout << i << ": " << (table[i] == -1 ? 0 : table[i]) << "\n";
        }

        else if (choice == 4) {
            break;
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}