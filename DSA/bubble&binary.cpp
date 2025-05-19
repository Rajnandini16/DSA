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
        cout << "\n1. Display\n2. Bubble Sort\n3. Binary Search\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Array: ";
            for (i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;

        } else if (choice == 2) {
            for (i = 0; i < n - 1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            cout << "Array sorted using Bubble Sort.\n";

        } else if (choice == 3) {
            cout << "Enter element to search: ";
            cin >> key;
            int low = 0, high = n - 1, mid, found = 0;

            while (low <= high) {
                mid = (low + high) / 2;
                if (arr[mid] == key) {
                    cout << "Element found at index " << mid << endl;
                    found = 1;
                    break;
                } else if (arr[mid] < key) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (!found)
                cout << "Element not found.\n";

        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;

        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}