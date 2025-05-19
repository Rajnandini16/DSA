#include <iostream>
using namespace std;

int main() {
    int R, S;
    cout << "Enter number of elements in array A: ";
    cin >> R;
    int A[R];
    cout << "Enter elements of sorted array A: ";
    for (int i = 0; i < R; i++) cin >> A[i];

    cout << "Enter number of elements in array B: ";
    cin >> S;
    int B[S];
    cout << "Enter elements of sorted array B: ";
    for (int i = 0; i < S; i++) cin >> B[i];

    int C[R + S];
    int NA = 0, NB = 0, PTR = 0;

    // Merge arrays
    while (NA < R && NB < S) {
        if (A[NA] < B[NB])
            C[PTR++] = A[NA++];
        else
            C[PTR++] = B[NB++];
    }

    while (NA < R) C[PTR++] = A[NA++];
    while (NB < S) C[PTR++] = B[NB++];

    int choice;
    cout << "\nMenu:\n1. Display Merged Array\n2. Search an Element\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Merged Array: ";
            for (int i = 0; i < R + S; i++)
                cout << C[i] << " ";
            cout << endl;
            break;

        case 2: {
            int key, index = -1;
            cout << "Enter element to search: ";
            cin >> key;

            int low = 0, high = R + S - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (C[mid] == key) {
                    index = mid;
                    break;
                } else if (C[mid] < key) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (index != -1)
                cout << "Element found at position: " << index + 1 << endl;
            else
                cout << "Element not found." << endl;
            break;
        }

        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
