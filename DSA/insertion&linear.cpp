#include <iostream>
using namespace std;

int main() {
    int arr[100], n, i, j, temp, key, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (i = 0; i < n; i++)
        cin >> arr[i];

    while (true) {
        cout << "\n1. Display\n2. Insertion Sort\n3. Linear Search\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Array: ";
            for (i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;

        } else if (choice == 2) {
            for (i = 1; i < n; i++) {
                temp = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > temp) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = temp;
            }
            cout << "Array sorted using Insertion Sort.\n";

        } else if (choice == 3) {
    cout << "Enter element to search: ";
    cin >> key;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            break;
        }
    }
    if (i == n)
        cout << "Element not found.\n";
    break;

        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;

        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
