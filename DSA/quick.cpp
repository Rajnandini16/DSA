#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) { 
    if (low >=high) return;

    int pivot=arr[high];
    int i=low;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
 swap(arr[i+1],arr[high]);

        quickSort(arr, low,i); 
        quickSort(arr, i+2, high); 
    } 
} 
int main() { 
    int n; 
    cout << "Enter number of elements: "; 
    cin >> n; 
    cout << "Enter " << n << " elements:\n"; 
    for (int i = 0; i < n; i++) 
        cin >> arr[i]; 
    quickSort(arr, 0, n - 1); 
    cout << "Sorted array: "; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
    return 0; 
}