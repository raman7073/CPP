#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    // Sort A in descending order
    sort(A.rbegin(), A.rend());

    // Initialize variables
    long long sumDegrees = 2 * (N - 1);
    long long fT = 0;

    // Calculate f(T)
    for (int i = 0; i < N; ++i)
    {
        long long d = min(sumDegrees, static_cast<long long>(i));
        fT += d * d * A[i];
        sumDegrees -= d;
        if (sumDegrees <= 0)
            break;
    }

    cout << fT << endl;

    return 0;
}
