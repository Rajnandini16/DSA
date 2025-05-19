#include <iostream>
using namespace std;

int main() {
    int arr[100], n, i;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (i = 0; i < n; i++)
        cin >> arr[i];

    // Heapify function implemented inline
    // To heapify subtree rooted at index i for heap size heap_size
    for (int heap_size = n; heap_size > 1; ) {
        // Build max heap (bottom-up)
        for (int i = heap_size / 2 - 1; i >= 0; i--) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < heap_size && arr[left] > arr[largest])
                largest = left;
            if (right < heap_size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                int temp = arr[i];
                arr[i] = arr[largest];
                arr[largest] = temp;

                // Continue heapifying from largest downwards
                int current = largest;
                while (true) {
                    int l = 2 * current + 1;
                    int r = 2 * current + 2;
                    int maxIndex = current;

                    if (l < heap_size && arr[l] > arr[maxIndex])
                        maxIndex = l;
                    if (r < heap_size && arr[r] > arr[maxIndex])
                        maxIndex = r;

                    if (maxIndex == current)
                        break;

                    temp = arr[current];
                    arr[current] = arr[maxIndex];
                    arr[maxIndex] = temp;

                    current = maxIndex;
                }
            }
        }

        // Swap root(max) with last element
        int temp = arr[0];
        arr[0] = arr[heap_size - 1];
        arr[heap_size - 1] = temp;

        heap_size--;
    }

    cout << "Sorted array using Heap Sort:\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}