#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return 0;  // Exit the program early when element is found
        }
    }

    // If the loop completes, the element was not found
    cout << "Element not found." << endl;

    return 0;
}
