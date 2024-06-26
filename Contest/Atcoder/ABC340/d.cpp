
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> A(N - 1), B(N - 1), X(N - 1);
    for (int i = 0; i < N - 1; ++i)
        cin >> A[i] >> B[i] >> X[i];

    long long min_time = 0;
    for (int i = N - 2; i >= 0; --i)
    {
        min_time = min(min_time + A[i], min_time + B[i] * (X[i] != i + 2));
    }

    cout << min_time << endl;

    return 0;
}
