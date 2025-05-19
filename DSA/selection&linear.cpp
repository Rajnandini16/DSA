#include <iostream>
using namespace std;

int main() {
    int arr[100], n, choice;

    // Input number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    // Input elements
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Menu-driven loop
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display Array\n";
        cout << "2. Selection Sort (with passes)\n";
        cout << "3. Linear Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Array: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
                break;

            case 2:
                for (int i = 0; i < n - 1; i++) {
                    int minIndex = i;
                    for (int j = i + 1; j < n; j++) {
                        if (arr[j] < arr[minIndex])
                            minIndex = j;
                    }

                    if (minIndex != i)
                        swap(arr[i], arr[minIndex]);

                    // Show array after each pass
                    cout << "Pass " << i + 1 << ": ";
                    for (int k = 0; k < n; k++)
                        cout << arr[k] << " ";
                    cout << endl;
                }
                cout << "Array sorted successfully.\n";
                break;

            case 3: {
                int key;
                cout << "Enter element to search: ";
                cin >> key;

                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        cout << "Element found at index " << i << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Element not found.\n";
                break;
            }

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
