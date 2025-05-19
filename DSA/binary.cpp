#include <iostream>
using namespace std;

int main() {
    int n, key, index=-1;
    cout << "Enter number of elements (in sorted order): ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " sorted elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
           index=mid;
           break;
        } else if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

if(index!=-1){
    cout<<"element found at index: "<<index+1;
}else{
    cout << "Element not found." << endl;
}
    return 0;
}
