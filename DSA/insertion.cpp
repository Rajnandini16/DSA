#include <iostream>
using namespace std;

int main() {
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        cout << "Pass " << i << ": ";
        for (int k = 0; k < n; k++)
            cout << a[k] << " ";
        cout << endl;
    }

    return 0;
}
