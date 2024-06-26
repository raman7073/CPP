#include <iostream>
#include <vector>

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

    vector<long long> S(N - 1), T(N - 1);
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> S[i] >> T[i];
    }

    long long currency_N = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        if (A[i] >= S[i])
        {
            A[i + 1] += (A[i] / S[i]) * T[i];
            A[i] = A[i] % S[i];
        }
    }

    cout << A[N - 1] << endl;

    return 0;
}
