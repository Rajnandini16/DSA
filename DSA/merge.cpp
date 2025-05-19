#include <iostream>
using namespace std;

int main() {
    int R, S;
    cout << "Enter the number of elements in array A: ";
    cin >> R;
    int A[R];
    cout << "Enter elements of sorted array A: ";
    for (int i = 0; i < R; i++) cin >> A[i];

    cout << "Enter the number of elements in array B: ";
    cin >> S;
    int B[S];
    cout << "Enter elements of sorted array B: ";
    for (int i = 0; i < S; i++) cin >> B[i];

    int C[R + S];
    int NA = 0, NB = 0, PTR = 0;

    while (NA < R && NB < S) {
        if (A[NA] < B[NB])
            C[PTR++] = A[NA++];
        else
            C[PTR++] = B[NB++];
    }

    while (NA < R) C[PTR++] = A[NA++];
    while (NB < S) C[PTR++] = B[NB++];

    cout << "Merged Array: ";
    for (int i = 0; i < R + S; i++) cout << C[i] << " ";
    cout << endl;

    return 0;
}
