#include <iostream>
#include <vector>

using namespace std;

vector<long long> reachTime(int N, vector<int> &H)
{
    vector<long long> operations(N);
    vector<long long> A(N + 1, 0);

    long long op_count = 0;
    for (int i = 0; i < N; ++i)
    {
        while (A[i] <= H[i])
        {
            A[i + 1]++;
            op_count++;
            if (i > 0 && A[i - 1] > A[i] && A[i - 1] > H[i])
            {
                A[i - 1]--;
                A[i]++;
            }
        }
        operations[i] = op_count;
    }

    return operations;
}

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> H[i];
    }

    vector<long long> result = reachTime(N, H);

    for (int i = 0; i < N; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
