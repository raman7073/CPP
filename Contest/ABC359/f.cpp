#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

long long findMinValue(int N, const vector<int> &A)
{
    // Find the minimum A[i]
    int minA = *min_element(A.begin(), A.end());

    // Calculate the sum of all elements in A
    long long sumA = 0;
    for (int i = 0; i < N; ++i)
    {
        sumA += A[i];
    }

    // The minimum value of f(T)
    long long minValue = (long long)(N - 1) * (N - 1) * minA + (sumA - minA);

    return minValue;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    cout << findMinValue(N, A) << endl;
    return 0;
}
