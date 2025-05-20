#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int N;
    cin >> N;
    int A[N][4];
    int P[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3];
    }
    for (int i = 0; i < N; i++) {
        sort(A[i], A[i] + 4);
        if (A[i][0] == A[i][3])
            P[i] = 50000 + 5000 * A[i][0];
        else if (A[i][0] == A[i][2])
            P[i] = 10000 + 1000 * A[i][0];
        else if (A[i][1] == A[i][3])
            P[i] = 10000 + 1000 * A[i][1];
        else if (A[i][0] == A[i][1] && A[i][2] == A[i][3])
            P[i] = 2000 + 500 * A[i][0] + 500 * A[i][2];
        else if (A[i][0] == A[i][1])
            P[i] = 1000 + 100 * A[i][0];
        else if (A[i][1] == A[i][2])
            P[i] = 1000 + 100 * A[i][1];
        else if (A[i][2] == A[i][3])
            P[i] = 1000 + 100 * A[i][2];
        else
            P[i] = 100 * A[i][3];
    }
    sort(P, P + N);
    cout << P[N - 1];
    return 0;
}