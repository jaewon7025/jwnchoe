#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int T;
    cin >> T;
    int A[T][10];
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < T; i++) {
        sort(A[i], A[i] + 10);
        cout << A[i][7] << '\n';
    }
}