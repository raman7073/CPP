#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read input
    int N;
    cin >> N;

    vector<long long> A(N);

    // Read the array A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }


    long long currentPassengers = 0;
    long long minPassengers = 0;

    for (int i = 0; i < N; ++i) {
        currentPassengers += A[i];
        minPassengers = min(minPassengers, currentPassengers);
    }

    cout << currentPassengers-minPassengers << endl;

    return 0;
}
